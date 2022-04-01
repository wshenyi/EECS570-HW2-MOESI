
-- Three-state 3-hop MSI protocol

----------------------------------------------------------------------
-- Constants
----------------------------------------------------------------------
const
  ProcCount: 3;          -- number processors
  ValueCount: 2;         -- number of data values.
  NumVCs: 3;             -- number of virtual channels
  RequestChannel: 0;     -- virtual channel #0
	ForwardChannel: 1;     -- virtual channel #1
	ResponseChannel: 2;    -- virtual channel #2
  NetMax: ProcCount+1;   -- num of proc plus 1 dir
  

----------------------------------------------------------------------
-- Types
----------------------------------------------------------------------
type
  Proc: scalarset(ProcCount);   -- unordered range of processors
  Value: scalarset(ValueCount); -- arbitrary values for tracking coherence
  Dir: enum { Directory };      -- need enumeration for IsMember calls
  Node: union { Dir , Proc };

  VCType:   0..NumVCs-1;
  AckCount: (1-ProcCount)..ProcCount-1;

  MessageType: enum {
                      -- Request channel
                      GetS,
                      GetM,
                      PutS,
                      PutM,
                      -- Response channel
                      Data,
                      InvAck,
                      InvAllAck,
                      PutAck,
                      FwdGetSAck,
                      FwdGetMAck,
                      -- Forward channel
                      Inv,
                      FwdGetS,
                      FwdGetM
                    };

  Message:
    Record
      mtype: MessageType;
      src:   Node;
      -- do not need a destination for verification; the destination is indicated by which array entry in the Net the message is placed
      vc: VCType;
      value: Value;
      fwd_to: Node;
      ack_cnt: AckCount;  
    End;

  DirState: -- Directory controller states
    Record
      state: enum {
                    -- Stable states
                    Dir_M,
      							Dir_S,
                    Dir_I,
                    -- Transition states
                    Dir_MX_D,
                    Dir_SM_A,
                    Dir_MM_A
                  };
      owner: Node;	-- Assuming has only one memory location
      value: Value;   -- Assuming has only one memory location
      sharers: multiset [ProcCount] of Node;
    End;

  ProcState: -- Cache controller states
    Record
      state: enum {
                    -- Stable states
                    Proc_M,
                    Proc_S,
                    Proc_I,
                    -- Transition states
                    Proc_IS_D,
                    Proc_IM_A,
                    Proc_IM_AD,
                    Proc_II_A,
                    Proc_SM_A,
                    Proc_SM_AD,
                    Proc_SI_A,
                    Proc_MI_A,
                    -- Additonal states
                    Proc_IS_DP
                  };
      value: Value;
      ack_cnt: AckCount; -- ack_cnt = 0 means don't need extra ack
    End;

----------------------------------------------------------------------
-- Variables
----------------------------------------------------------------------
var
  DirNode:  DirState;
  Procs: array [Proc] of ProcState;
  Net:   array [Node] of multiset [NetMax] of Message; -- One multiset for each destination - messages are arbitrarily reordered by the multiset
  InBox: array [Node] of array    [VCType] of Message; -- If a message is not processed, it is placed in InBox, blocking that virtual channel
  msg_processed: boolean;
  LastWrite: Value; -- Used to confirm that writes are not lost; this variable would not exist in real hardware

----------------------------------------------------------------------
-- Procedures
----------------------------------------------------------------------
Procedure Send(
                mtype:   MessageType;
                dst:     Node;
                src:     Node;
                vc:      VCType;
                value:   Value;
                fwd_to:  Node;
                ack_cnt: AckCount;
              );
var msg:Message;
Begin
  Assert (MultiSetCount(i: Net[dst], true) < NetMax) "Too many messages";
  msg.mtype   := mtype;
  msg.src     := src;
  msg.vc      := vc;
  msg.value   := value;
  msg.fwd_to  := fwd_to;
  msg.ack_cnt := ack_cnt;
  MultiSetAdd(msg, Net[dst]);
End;

Procedure ErrorUnhandledMsg(msg: Message; n: Node);
Begin
  put "\n====================Error Msg====================\n";
  put "mtype: ";
  put msg.mtype;
  put "\n";
  put "src: ";
  put msg.src;
  put "\n";
  put "src_state: ";
  if IsMember(msg.src, Proc) then
    put Procs[msg.src].state;
  else
    put DirNode.state;
  endif;
  put "dst_state: ";
  if IsMember(n, Proc) then
    put Procs[n].state;
  else
    put DirNode.state;
  endif;
  put "\n";
  error "Unhandled message type!";
End;

Procedure ErrorUnhandledState();
Begin
  error "Unhandled state!";
End;

Procedure AddToSharersList(n: Node);
Begin
  if MultiSetCount(i:DirNode.sharers, DirNode.sharers[i] = n) = 0
  then
    MultiSetAdd(n, DirNode.sharers);
  endif;
End;

Function IsSharer(n: Node) : Boolean;
Begin
  return MultiSetCount(i: DirNode.sharers, DirNode.sharers[i] = n) > 0
End;

Function IsSharerListEmpty() : Boolean;
Begin
  return MultiSetCount(i: DirNode.sharers, true) = 0
End;

Procedure RemoveFromSharersList(n: Node);
Begin
  MultiSetRemovePred(i: DirNode.sharers, DirNode.sharers[i] = n);
End;

-- Sends a message to all sharers except rqst
Procedure SendInvReqToSharers(rqst: Node);
Begin
  for p : Proc do
    if IsSharer(p) & p != rqst then
      Send(Inv, p, Directory, ForwardChannel, UNDEFINED, rqst, 0)
    endif;
  endfor;
End;

Procedure DirReceive(msg: Message);
var cnt:0..ProcCount;  -- for counting sharers
Begin
-- Debug output may be helpful:
--  put "Receiving "; put msg.mtype; put " on VC"; put msg.vc; 
--  put " at Directory -- "; put DirNode.state;

  cnt := MultiSetCount(i: DirNode.sharers, true);

  -- default to 'processing' message. set to false otherwise
  msg_processed := true;

  switch DirNode.state
  case Dir_I:
    switch msg.mtype
    case GetS:
      DirNode.state := Dir_S;
      AddToSharersList(msg.src);
      Send(Data, msg.src, Directory, ResponseChannel, DirNode.value, UNDEFINED, 0);
		case GetM:
			DirNode.state := Dir_M;
			DirNode.owner := msg.src;
			Send(Data, msg.src, Directory, ResponseChannel, DirNode.value, UNDEFINED, cnt);
		case PutS:
			Send(PutAck, msg.src, Directory, ResponseChannel, UNDEFINED, UNDEFINED, 0);
		case PutM:
			assert (msg.src != DirNode.owner) "error at Dir_I: PutM from owner";
			Send(PutAck, msg.src, Directory, ResponseChannel, UNDEFINED, UNDEFINED, 0);
		else
			ErrorUnhandledMsg(msg, Directory);
		endswitch;

  case Dir_S:
    switch msg.mtype
    case GetS:
      AddToSharersList(msg.src);
      Send(Data, msg.src, Directory, ResponseChannel, DirNode.value, UNDEFINED, 0);
		case GetM:
      if IsSharer(msg.src) then
        if cnt = 1 then
          DirNode.state := Dir_M;
        else
          DirNode.state := Dir_SM_A;
          SendInvReqToSharers(msg.src);
        endif;
        Send(Data, msg.src, Directory, ResponseChannel, DirNode.value, UNDEFINED, cnt-1);
      else
        DirNode.state := Dir_SM_A;
        SendInvReqToSharers(msg.src);
        Send(Data, msg.src, Directory, ResponseChannel, DirNode.value, UNDEFINED, cnt);
      endif;
      undefine DirNode.sharers;
			DirNode.owner := msg.src;
		case PutS:
			Send(PutAck, msg.src, Directory, ResponseChannel, UNDEFINED, UNDEFINED, 0);      
      if IsSharer(msg.src) then
        if cnt = 1 then
          DirNode.state := Dir_I;
        endif;
        RemoveFromSharersList(msg.src);
      endif;
		case PutM:
			assert (msg.src != DirNode.owner) "error at Dir_S: PutM from owner";
			Send(PutAck, msg.src, Directory, ResponseChannel, UNDEFINED, UNDEFINED, 0);
      RemoveFromSharersList(msg.src);
		else
			ErrorUnhandledMsg(msg, Directory);
		endswitch;

  case Dir_M:
    switch msg.mtype
    case GetS:
      DirNode.state := Dir_MX_D;
      Send(FwdGetS, DirNode.owner, Directory, ForwardChannel, UNDEFINED, msg.src, 0);
      AddToSharersList(msg.src);
      AddToSharersList(DirNode.owner);
      DirNode.owner := Directory;
    case GetM:
      DirNode.state := Dir_MM_A;
      Send(FwdGetM, DirNode.owner, Directory, ForwardChannel, UNDEFINED, msg.src, 0);
      DirNode.value := msg.value;
      DirNode.owner := msg.src;
    case PutS:
      Send(PutAck, msg.src, Directory, ResponseChannel, UNDEFINED, UNDEFINED, 0);
    case PutM:
      if DirNode.owner = msg.src then
        DirNode.value := msg.value;
        LastWrite := DirNode.value;
        DirNode.owner := Directory;
        DirNode.state := Dir_I;
      endif;
      Send(PutAck, msg.src, Directory, ResponseChannel, UNDEFINED, UNDEFINED, 0);
    else
      ErrorUnhandledMsg(msg, Directory);
    endswitch;

  case Dir_MX_D:
    switch msg.mtype
    case GetS:
      msg_processed := false;
    case GetM:
      msg_processed := false;
    case PutS:
      msg_processed := false;
    case PutM:
      msg_processed := false;
    case FwdGetSAck:
      if cnt = 0 then
        DirNode.state := Dir_I;
      else
        DirNode.state := Dir_S;
      endif;
      DirNode.value := msg.value;
      LastWrite := DirNode.value;
    case Data:
      if cnt = 0 then
        DirNode.state := Dir_I;
      else
        DirNode.state := Dir_S;
      endif;
      DirNode.value := msg.value;
      LastWrite := DirNode.value;
    else
      ErrorUnhandledMsg(msg, Directory);
    endswitch;
  
  case Dir_MM_A:
    switch msg.mtype
    case GetS:
      msg_processed := false;
    case GetM:
      msg_processed := false;
    case PutS:
      msg_processed := false;
    case PutM:
      msg_processed := false;
    case Data:
      msg_processed := false;
    case FwdGetMAck:
      DirNode.state := Dir_M;
    else
      ErrorUnhandledMsg(msg, Directory);
    endswitch;

  case Dir_SM_A:
    switch msg.mtype
    case GetS:
      msg_processed := false;
    case GetM:
      msg_processed := false;
    case PutS:
      msg_processed := false;
    case PutM:
      msg_processed := false;
    case Data:
      msg_processed := false;
    case InvAllAck:
      DirNode.state := Dir_M;
    else
      ErrorUnhandledMsg(msg, Directory);
    endswitch;

  endswitch;
End;


Procedure ProcReceive(msg: Message; p: Proc);
Begin
--  put "Receiving "; put msg.mtype; put " on VC"; put msg.vc; 
--  put " at proc "; put p; put "\n";

  -- default to 'processing' message.  set to false otherwise
  msg_processed := true;

  alias pstate:Procs[p].state do
  alias pvalue:Procs[p].value do
  alias pcnt:  Procs[p].ack_cnt do

  switch pstate
  case Proc_I:
    switch msg.mtype
    case Inv:
      Send(InvAck, msg.fwd_to, p, ResponseChannel, UNDEFINED, UNDEFINED, 0);
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case Proc_IS_D:
    switch msg.mtype
    case Inv:
      Send(InvAck, msg.fwd_to, p, ResponseChannel, UNDEFINED, UNDEFINED, 0);
      pstate := Proc_IS_DP;
      -- msg_processed := false;
    case Data:
      if (msg.ack_cnt = 0 & msg.src = Directory) | DirNode.owner = msg.src then
        pstate := Proc_S;
      endif;
      pvalue := msg.value;
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case Proc_IS_DP:
    switch msg.mtype
    case Data:
      pstate := Proc_I;
      undefine pvalue;
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case Proc_IM_AD:
    switch msg.mtype
    case FwdGetS:
      msg_processed := false;
    case FwdGetM:
      msg_processed := false;
    case Data:
      if msg.src = Directory then -- data is from directory controller
        if msg.ack_cnt = 0 then
          pstate := Proc_M;
        else
          assert (pcnt <= 0) "error at Proc_IM_AD, ack_cnt > 0.";
          pcnt :=  pcnt + msg.ack_cnt;
          if pcnt = 0 then
            pstate := Proc_M;
            Send(InvAllAck, Directory, p, ResponseChannel, UNDEFINED, UNDEFINED, 0);
          else
            pstate := Proc_IM_A;
          endif;
        endif;
      else -- data is from previous owner
        -- pcnt := 0;
        pstate := Proc_M;
      endif;
      pvalue := msg.value;
    case InvAck:
      pcnt := pcnt - 1;
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case Proc_IM_A:
    switch msg.mtype
    case FwdGetS:
      msg_processed := false;
    case FwdGetM:
      msg_processed := false;
    case InvAck:
      -- assert (pcnt = 0) "Proc_IM_A pcnt == 0.";

      pcnt := pcnt - 1;
      if pcnt = 0 then
        pstate := Proc_M;
        Send(InvAllAck, Directory, p, ResponseChannel, UNDEFINED, UNDEFINED, 0);
      endif;
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case Proc_S:
    switch msg.mtype
    case Inv:
      pstate := Proc_I;
      Send(InvAck, msg.fwd_to, p, ResponseChannel, UNDEFINED, UNDEFINED, 0);
      undefine pvalue;
    case PutAck:

    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case Proc_SM_AD:
    switch msg.mtype
    case FwdGetS:
      msg_processed := false;
    case FwdGetM:
      msg_processed := false;
    case Inv:
      pstate := Proc_IM_AD;
      Send(InvAck, msg.fwd_to, p, ResponseChannel, UNDEFINED, UNDEFINED, 0);
    case Data:
      assert (msg.src = Directory) "error at Proc_SM_AD, Data not from dir.";
      if msg.ack_cnt = 0 then
        pstate := Proc_M;
      else
        assert (pcnt <= 0) "error at Proc_SM_AD, ack_cnt > 0.";
        pcnt :=  pcnt + msg.ack_cnt;
        if pcnt = 0 then
          pstate := Proc_M;
          Send(InvAllAck, Directory, p, ResponseChannel, UNDEFINED, UNDEFINED, 0);
        else
          pstate := Proc_SM_A;
        endif;
      endif;
      pvalue := msg.value;
    case InvAck:
      -- assert (pcnt = 0) "error at Proc_SM_AD, ack_cnt == 0.";
      pcnt := pcnt - 1;
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case Proc_SM_A:
    switch msg.mtype
    case FwdGetS:
      msg_processed := false;
    case FwdGetM:
      msg_processed := false;
    case InvAck:
      pcnt := pcnt - 1;
      if pcnt = 0 then
        pstate := Proc_M;
        Send(InvAllAck, Directory, p, ResponseChannel, UNDEFINED, UNDEFINED, 0);
      endif;
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case Proc_M:
    switch msg.mtype
    case FwdGetS:
      pstate := Proc_S;
      Send(FwdGetSAck, Directory,  p, ResponseChannel, pvalue, UNDEFINED, 0);
      Send(Data, msg.fwd_to, p, ResponseChannel, pvalue, UNDEFINED, 0);
    case FwdGetM:
      pstate := Proc_I;
      Send(Data, msg.fwd_to, p, ResponseChannel, pvalue, UNDEFINED, 0);
      Send(FwdGetMAck, Directory,  p, ResponseChannel, UNDEFINED, UNDEFINED, 0);
      undefine pvalue;
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case Proc_MI_A:
    switch msg.mtype
    case FwdGetS:
      pstate := Proc_SI_A;
      Send(FwdGetSAck, Directory,  p, ResponseChannel, pvalue, UNDEFINED, 0);
      Send(Data, msg.fwd_to, p, ResponseChannel, pvalue, UNDEFINED, 0);
    case FwdGetM:
      pstate := Proc_II_A;
      Send(Data, msg.fwd_to, p, ResponseChannel, pvalue, UNDEFINED, 0);
      Send(FwdGetMAck, Directory,  p, ResponseChannel, UNDEFINED, UNDEFINED, 0);
    case PutAck:
      pstate := Proc_I;
      undefine pvalue;
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case Proc_SI_A:
    switch msg.mtype
    case Inv:
      pstate := Proc_II_A;
      Send(InvAck, msg.fwd_to,  p, ResponseChannel, UNDEFINED, UNDEFINED, 0);
    case PutAck:
      pstate := Proc_I;
      undefine pvalue;
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case Proc_II_A:
    switch msg.mtype
    case PutAck:
      pstate := Proc_I;
      undefine pvalue;
    else
      ErrorUnhandledMsg(msg,  p);
    endswitch;

  else
    ErrorUnhandledState();
  endswitch;
  
  endalias;
  endalias;
  endalias;
End;

----------------------------------------------------------------------
-- Rules
----------------------------------------------------------------------

-- Processor state transition of processor requests for the MSI protocol

ruleset n: Proc Do
  alias p: Procs[n] Do

    rule "M ==(evict)==> I"
      p.state = Proc_M
    ==>
      Send(PutM, Directory, n, RequestChannel, p.value, UNDEFINED, 0);
      p.state := Proc_MI_A;
    endrule;

    rule "S ==(evict)==> I"
      p.state = Proc_S
    ==>
      Send(PutS, Directory, n, RequestChannel, UNDEFINED, UNDEFINED, 0);
      p.state := Proc_SI_A;
    endrule;

    rule "S ==(store)==> M"
      p.state = Proc_S
    ==>
      Send(GetM, Directory, n, RequestChannel, UNDEFINED, UNDEFINED, 0);
      p.state := Proc_SM_AD;
    endrule;

    rule "I ==(store)==> M"
      p.state = Proc_I
    ==>
      Send(GetM, Directory, n, RequestChannel, UNDEFINED, UNDEFINED, 0);
      p.state := Proc_IM_AD;
    endrule;

    rule "I ==(load)==> S"
      p.state = Proc_I 
    ==>
      Send(GetS, Directory, n, RequestChannel, UNDEFINED, UNDEFINED, 0);
      p.state := Proc_IS_D;
    endrule;

  endalias;
endruleset;

-- Message delivery rules
ruleset n:Node do
  choose msg_idx:Net[n] do
    alias chan:Net[n] do -- a proc or the dir
    alias msg:chan[msg_idx] do
    alias box:InBox[n] do
      -- Pick a random message in the network and delivier it
      rule "receive-net"
        (isundefined(box[msg.vc].mtype))
      ==>

        if IsMember(n, Dir)
        then
          DirReceive(msg);
        else
          ProcReceive(msg, n);
        endif;

        if ! msg_processed
        then
          -- The node refused the message, stick it in the InBox to block the VC.
          box[msg.vc] := msg;
        endif;
      
        MultiSetRemove(msg_idx, chan);
      
      endrule;

    endalias
    endalias;
    endalias;
  endchoose;  

	-- Try to deliver a message from a blocked VC; perhaps the node can handle it now
	ruleset vc:VCType do
    rule "receive-blocked-vc"
			(! isundefined(InBox[n][vc].mtype))
    ==>
      if IsMember(n, Dir)
      then
        DirReceive(InBox[n][vc]);
      else
        ProcReceive(InBox[n][vc], n);
			endif;

			if msg_processed
			then
				-- Message has been handled, forget it
	  		undefine InBox[n][vc];
			endif;

    endrule;
  endruleset;

endruleset;

----------------------------------------------------------------------
-- Startstate
----------------------------------------------------------------------
startstate

  -- directory node initialization
  DirNode.state := Dir_I;
  DirNode.owner := Directory;
  undefine DirNode.sharers;
	For v: Value do
    DirNode.value := v;
	endfor;
	LastWrite := DirNode.value;
  
  -- processor initialization
  for i: Proc do
    Procs[i].state := Proc_I;
    Procs[i].ack_cnt := 0;
    undefine Procs[i].value;
  endfor;

  -- network initialization
  undefine Net;
endstartstate;

----------------------------------------------------------------------
-- Invariants
----------------------------------------------------------------------
--- Contriants for DirNode.owner
invariant "Directory in I or S state implies empty owner"
  (DirNode.state = Dir_I | DirNode.state = Dir_S)
    ->
      DirNode.owner = Directory;

invariant "Directory in M state implies owner exists"
  DirNode.state = Dir_M
    ->
      DirNode.owner != Directory;

--- Contriants for DirNode.sharers
invariant "Directory in I or M state implies empty sharer list"
  (DirNode.state = Dir_I | DirNode.state = Dir_M)
    ->
      MultiSetCount(i: DirNode.sharers, true) = 0;

invariant "Directory in S state implies non-empty sharer list"
  DirNode.state = Dir_S
    ->
      MultiSetCount(i: DirNode.sharers, true) > 0;

--- Contriants for value
invariant "Processor in S state implies the value match memory"
  Forall n : Proc Do	
    (DirNode.state = Dir_S & Procs[n].state = Proc_S)
      ->
			  DirNode.value = Procs[n].value
	end;	
	
invariant "Processor in I state implies the value is undefined"
  Forall n : Proc Do	
    Procs[n].state = Proc_I
      ->
			  IsUndefined(Procs[n].value)
	end;

-- @@@ Begin Mandatory Invariants
-- Coherence
invariant "Values in memory matches value of last write, when shared or invalid"
  Forall n : Proc Do	
    (DirNode.state = Dir_S | DirNode.state = Dir_I)
      ->
			  DirNode.value = LastWrite
	end;

invariant "Processors in a valid state (S or M) match last write"
  Forall n : Proc Do 
    (Procs[n].state = Proc_S | Procs[n].state = Proc_M)
      ->
        Procs[n].value = LastWrite -- LastWrite is updated whenever a new value is written 
 end;

-- Single Writer Multiple Reader
invariant "If processor is in Modified state, there are no Sharers"
  Forall n : Proc Do
    Forall m : Proc Do
      ((Procs[n].state = Proc_M) & (n != m)) 
        -> 
          (Procs[m].state != Proc_S & Procs[m].state != Proc_M)
    end
  end;

-- Precise Sharer Tracking
invariant "Invalid Processors are not present on Sharer's List"
  Forall n : Proc Do
    (Procs[n].state = Proc_I) -> (MultiSetCount(i: DirNode.sharers, DirNode.sharers[i] = n) = 0)
  end;
-- @@@ End Mandatory Invariants