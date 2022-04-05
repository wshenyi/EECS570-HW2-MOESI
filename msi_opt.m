

-- Three-state 3-hop MOESI protocol

----------------------------------------------------------------------
-- Constants
----------------------------------------------------------------------
const
  ProcCount: 3;          -- number processors
  ValueCount: 3;         -- number of data values.
  NumVCs: 4;             -- number of virtual channels
  RequestChannel: 0;     -- virtual channel #0
	ForwardChannel: 1;     -- virtual channel #1
	ResponseChannel: 2;    -- virtual channel #2
  DataChannel:     3;    -- virtual channel #3
  NetMax: ProcCount+2;   -- number of proc + 1 directory + 1 extra
  

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
                      PutE,
                      PutO,
                      PutM,
                      DownM,
                      DownO,
                      -- Data channel
                      Data,
                      EData,
                      -- Response channel
                      InvAck,
                      PutAck,
                      FwdGetSAck,
                      FwdGetMAck,
                      AckCnt,
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
                    Dir_O,
                    Dir_E,
      							Dir_S,
                    Dir_I,
                    -- Transition states
                    Dir_MX_D,
                    Dir_OX_D,
                    Dir_EX_A,
                    Dir_MM_A,
                    Dir_OM_AA,
                    Dir_OM_A,
                    Dir_EM_A,
                    Dir_SM_A
                  };
      owner: Node;	-- Assuming has only one memory location
      value: Value;   -- Assuming has only one memory location
      sharers: multiset [ProcCount] of Node;
      ack_cnt: AckCount;
    End;

  ProcState: -- Cache controller states
    Record
      state: enum {
                    -- Stable states
                    Proc_M,
                    Proc_O,
                    Proc_E,
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
                    Proc_EI_A,
                    Proc_EM_A,
                    Proc_OI_A,
                    Proc_OM_A,
                    Proc_OM_AC,
                    Proc_MI_A
                  };
      value: Value;
      sharers: multiset [ProcCount] of Node;
      -- dirty: boolean;
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

Function IsLocalSharerListEmpty(src: Node) : Boolean;
Begin
  return MultiSetCount(i: Procs[src].sharers, true) = 0
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

Procedure SendInvReqToLocalSharerList(rqst: Node);
Begin
  for p : Proc do
    if MultiSetCount(i: Procs[rqst].sharers, Procs[rqst].sharers[i] = p) > 0 & p != rqst then
      Send(Inv, p, Directory, ForwardChannel, UNDEFINED, rqst, 0)
    endif;
  endfor;
End;

Procedure SaveSharersListToLocal(dst: Node);
Begin
  for p : Node do
    if p != DirNode.owner & IsSharer(p) & p != dst & MultiSetCount(i: Procs[dst].sharers, Procs[dst].sharers[i] = p) = 0 then
      MultiSetAdd(p,  Procs[dst].sharers)
    endif;
  endfor;
  assert MultiSetCount(i: Procs[dst].sharers, true) > 0 "Save sharer list failed.";
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
      DirNode.state := Dir_E;
      DirNode.owner := msg.src;
      Send(EData, msg.src, Directory, DataChannel, DirNode.value, UNDEFINED, 0);
		case GetM:
			DirNode.state := Dir_M;
			DirNode.owner := msg.src;
			Send(Data, msg.src, Directory, DataChannel, DirNode.value, UNDEFINED, cnt);
		case PutS:
			Send(PutAck, msg.src, Directory, ResponseChannel, UNDEFINED, UNDEFINED, 0);
		case PutM:
			assert (msg.src != DirNode.owner) "error at Dir_I: PutM from owner";
			Send(PutAck, msg.src, Directory, ResponseChannel, UNDEFINED, UNDEFINED, 0);
    case PutE:
			assert (msg.src != DirNode.owner) "error at Dir_I: PutE from owner";
			Send(PutAck, msg.src, Directory, ResponseChannel, UNDEFINED, UNDEFINED, 0);
    case PutO:
			assert (msg.src != DirNode.owner) "error at Dir_I: PutO from owner";
			Send(PutAck, msg.src, Directory, ResponseChannel, UNDEFINED, UNDEFINED, 0);
		else
			ErrorUnhandledMsg(msg, Directory);
		endswitch;

  case Dir_S:
    assert !IsSharerListEmpty() "Error at Dir_S: cnt == 0";
    switch msg.mtype
    case GetS:
      AddToSharersList(msg.src);
      Send(Data, msg.src, Directory, DataChannel, DirNode.value, UNDEFINED, 0);
		case GetM:
      if IsSharer(msg.src) then
        if cnt = 1 then
          DirNode.state := Dir_M;
        else
          DirNode.state := Dir_SM_A;
          DirNode.ack_cnt := cnt - 1;
          SendInvReqToSharers(msg.src);
        endif;
        Send(Data, msg.src, Directory, DataChannel, DirNode.value, UNDEFINED, cnt - 1);
      else
        DirNode.state := Dir_SM_A;
        DirNode.ack_cnt := cnt;
        SendInvReqToSharers(msg.src);
        Send(Data, msg.src, Directory, DataChannel, DirNode.value, UNDEFINED, cnt);
      endif;
      undefine DirNode.sharers;
			DirNode.owner := msg.src;
		case PutS:
			Send(PutAck, msg.src, Directory, ResponseChannel, UNDEFINED, UNDEFINED, 0); 
      RemoveFromSharersList(msg.src);
      if IsSharerListEmpty() then
        DirNode.state := Dir_I;
      endif;
		case PutM:
      -- assert (msg.src != DirNode.owner) "error at Dir_S: PutM from owner";
			Send(PutAck, msg.src, Directory, ResponseChannel, UNDEFINED, UNDEFINED, 0);
      RemoveFromSharersList(msg.src);
      if IsSharerListEmpty() then
        DirNode.state := Dir_I;
      endif;
    case PutE:
    --  assert (msg.src != DirNode.owner) "error at Dir_S: PutE from owner";
			Send(PutAck, msg.src, Directory, ResponseChannel, UNDEFINED, UNDEFINED, 0);
      RemoveFromSharersList(msg.src);
      if IsSharerListEmpty() then
        DirNode.state := Dir_I;
      endif;
    case PutO:
      -- assert (msg.src != DirNode.owner) "error at Dir_S: PutO from owner";
			Send(PutAck, msg.src, Directory, ResponseChannel, UNDEFINED, UNDEFINED, 0);
      RemoveFromSharersList(msg.src);
      if IsSharerListEmpty() then
        DirNode.state := Dir_I;
      endif;
		else
			ErrorUnhandledMsg(msg, Directory);
		endswitch;

  case Dir_E:
    switch msg.mtype
    case GetS:
      DirNode.state := Dir_EX_A;
      Send(FwdGetS, DirNode.owner, Directory, ForwardChannel, UNDEFINED, msg.src, 0);
      AddToSharersList(msg.src);
      AddToSharersList(DirNode.owner);
    case GetM:
      assert IsSharerListEmpty() "Sharer list not empty";
      DirNode.state := Dir_EM_A;
      Send(FwdGetM, DirNode.owner, Directory, ForwardChannel, UNDEFINED, msg.src, 0);
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
    case PutO:
      if DirNode.owner = msg.src then
        DirNode.value := msg.value;
        LastWrite := DirNode.value;
        DirNode.owner := Directory;
        DirNode.state := Dir_I;
      endif;
      Send(PutAck, msg.src, Directory, ResponseChannel, UNDEFINED, UNDEFINED, 0);
    case PutE:
      if DirNode.owner = msg.src then
        DirNode.owner := Directory;
        DirNode.state := Dir_I;
      endif;
      Send(PutAck, msg.src, Directory, ResponseChannel, UNDEFINED, UNDEFINED, 0);
    else
      ErrorUnhandledMsg(msg, Directory);
    endswitch;

  case Dir_O:
    assert !IsSharerListEmpty() "Error at Dir_O: cnt == 0";
    switch msg.mtype
    case GetS:
      assert IsSharer(DirNode.owner) "Error at Dir_O: owner is not a sharer.";
      DirNode.state := Dir_OX_D; -- TODO
      Send(FwdGetS, DirNode.owner, Directory, ForwardChannel, UNDEFINED, msg.src, 0);
      AddToSharersList(msg.src);
		case GetM:
      if IsSharer(msg.src) then -- GetM from O or S state
        if msg.src = DirNode.owner then -- GetM from O state
          if cnt = 1 then
            DirNode.state := Dir_OM_A;
          else
            DirNode.state := Dir_OM_AA;
            DirNode.ack_cnt := cnt - 1;
            SaveSharersListToLocal(msg.src);
            -- SendInvReqToSharers(msg.src);
          endif;
          Send(FwdGetM, DirNode.owner, Directory, ForwardChannel, UNDEFINED, msg.src, cnt - 1);
        else -- GetM from S state
          if cnt = 2 then
            DirNode.state := Dir_OM_A;
          else
            DirNode.state := Dir_OM_AA;
            DirNode.ack_cnt := cnt - 2;
            SaveSharersListToLocal(msg.src);
            Send(AckCnt, msg.src, Directory, ResponseChannel, UNDEFINED, UNDEFINED, cnt - 2);
          endif;
          Send(FwdGetM, DirNode.owner, Directory, ForwardChannel, UNDEFINED, msg.src, 0);
        endif;
      else -- GetM from I state
        if cnt = 1 then
          DirNode.state := Dir_OM_A;
        else
          DirNode.state := Dir_OM_AA;
          DirNode.ack_cnt := cnt - 1;
          SaveSharersListToLocal(msg.src);
          Send(AckCnt, msg.src, Directory, ResponseChannel, UNDEFINED, UNDEFINED, cnt - 1);
        endif;
        Send(FwdGetM, DirNode.owner, Directory, ForwardChannel, UNDEFINED, msg.src, 0);
      endif;
      undefine DirNode.sharers;
      DirNode.owner := msg.src;
		case PutS:
			Send(PutAck, msg.src, Directory, ResponseChannel, UNDEFINED, UNDEFINED, 0); 
      RemoveFromSharersList(msg.src);
      if IsSharerListEmpty() then
        DirNode.state := Dir_I;
      endif;
		case PutM:
			Send(PutAck, msg.src, Directory, ResponseChannel, UNDEFINED, UNDEFINED, 0);
      RemoveFromSharersList(msg.src);
      if IsSharerListEmpty() then
        DirNode.state := Dir_I;
        DirNode.owner := Directory;
      else
        if DirNode.owner = msg.src then
          DirNode.value := msg.value;
          LastWrite := DirNode.value;
          DirNode.state := Dir_S;
          DirNode.owner := Directory;
        else
          DirNode.state := Dir_O;
        endif;
      endif;
    case PutE:
			Send(PutAck, msg.src, Directory, ResponseChannel, UNDEFINED, UNDEFINED, 0);
      RemoveFromSharersList(msg.src);
      if IsSharerListEmpty() then
        DirNode.state := Dir_I;
        DirNode.owner := Directory;
      else
        if DirNode.owner = msg.src then
          DirNode.state := Dir_S;
          DirNode.owner := Directory;
        else
          DirNode.state := Dir_O;
        endif;
      endif;
    case PutO:
      Send(PutAck, msg.src, Directory, ResponseChannel, UNDEFINED, UNDEFINED, 0);
      RemoveFromSharersList(msg.src);
      if IsSharerListEmpty() then
        DirNode.state := Dir_I;
        DirNode.owner := Directory;
      else
        if DirNode.owner = msg.src then
          DirNode.value := msg.value;
          LastWrite := DirNode.value;
          DirNode.state := Dir_S;
          DirNode.owner := Directory;
        else
          DirNode.state := Dir_O;
        endif;
      endif;
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
    case GetM:
      DirNode.state := Dir_MM_A;
      Send(FwdGetM, DirNode.owner, Directory, ForwardChannel, UNDEFINED, msg.src, 0);
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
    case PutE:
      assert (msg.src != DirNode.owner) "error at Dir_M: PutE from owner";
      Send(PutAck, msg.src, Directory, ResponseChannel, UNDEFINED, UNDEFINED, 0);
    case PutO:
      assert (msg.src != DirNode.owner) "error at Dir_M: PutO from owner"; 
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
    case PutO:
      msg_processed := false;
    case PutE:
      msg_processed := false;
    case FwdGetSAck:
      if cnt = 0 then
        DirNode.state := Dir_I;
      else
        DirNode.state := Dir_O;
        AddToSharersList(DirNode.owner);
      endif;
      -- DirNode.value := msg.value;
      -- LastWrite := DirNode.value;
    case FwdGetMAck:
      DirNode.state := Dir_M; -- TODO
      DirNode.value := msg.value;
      LastWrite := DirNode.value;
      undefine DirNode.sharers;
    else
      ErrorUnhandledMsg(msg, Directory);
    endswitch;

  case Dir_OX_D:
    switch msg.mtype
    case GetS:
      msg_processed := false;
    case GetM:
      msg_processed := false;
    case PutS:
      msg_processed := false;
    case PutM:
      msg_processed := false;
    case PutO:
      msg_processed := false;
    case PutE:
      msg_processed := false;
    case FwdGetSAck:
      if cnt = 0 then
        DirNode.state := Dir_I;
      else
        DirNode.state := Dir_O;
      endif;
    else
      ErrorUnhandledMsg(msg, Directory);
    endswitch;
  
  case Dir_EX_A:
    switch msg.mtype
    case GetS:
      msg_processed := false;
    case GetM:
      msg_processed := false;
    case PutS:
      msg_processed := false;
    case PutM:
      msg_processed := false;
    case PutO:
      msg_processed := false;
    case PutE:
      msg_processed := false;
    case FwdGetMAck:
      if cnt = 0 then
        DirNode.state := Dir_M;
      else
        DirNode.state := Dir_O;
      endif;
    case FwdGetSAck:
      DirNode.state := Dir_O;
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
    case PutO:
      msg_processed := false;
    case PutE:
      msg_processed := false;
    case Data:
      msg_processed := false;
    case FwdGetMAck:
      DirNode.state := Dir_M;
    else
      ErrorUnhandledMsg(msg, Directory);
    endswitch;

  case Dir_OM_AA:
    switch msg.mtype
    case GetS:
      msg_processed := false;
    case GetM:
      msg_processed := false;
    case PutS:
      msg_processed := false;
    case PutM:
      msg_processed := false;
    case PutO:
      msg_processed := false;
    case PutE:
      msg_processed := false;
    case Data:
      msg_processed := false;
    case InvAck:
      msg_processed := false;
    case FwdGetMAck:
      assert !IsUndefined(msg.fwd_to) "Undefine error!";
      SendInvReqToLocalSharerList(msg.fwd_to);
      DirNode.state := Dir_OM_A;
    else
      ErrorUnhandledMsg(msg, Directory);
    endswitch;
  
  case Dir_OM_A:
    switch msg.mtype
    case GetS:
      msg_processed := false;
    case GetM:
      msg_processed := false;
    case PutS:
      msg_processed := false;
    case PutM:
      msg_processed := false;
    case PutO:
      msg_processed := false;
    case PutE:
      msg_processed := false;
    case Data:
      msg_processed := false;
    case InvAck:
      assert DirNode.ack_cnt > 0 "Error at Dir_OM_A: DirNode.ack_cnt == 0.";
      DirNode.ack_cnt := DirNode.ack_cnt - 1;
      if DirNode.ack_cnt = 0 then
        DirNode.state := Dir_M;
      endif;
    case FwdGetMAck:
      DirNode.state := Dir_M;
    else
      ErrorUnhandledMsg(msg, Directory);
    endswitch;

  case Dir_EM_A:
    switch msg.mtype
    case GetS:
      msg_processed := false;
    case GetM:
      msg_processed := false;
    case PutS:
      msg_processed := false;
    case PutM:
      msg_processed := false;
    case PutO:
      msg_processed := false;
    case PutE:
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
    case PutO:
      msg_processed := false;
    case PutE:
      msg_processed := false;
    case Data:
      msg_processed := false;
    case InvAck:
      assert DirNode.ack_cnt > 0 "Error at Dir_SM_A: DirNode.ack_cnt == 0.";
      DirNode.ack_cnt := DirNode.ack_cnt - 1;
      if DirNode.ack_cnt = 0 then
        DirNode.state := Dir_M;
      endif;
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
      Send(InvAck, msg.fwd_to,  p, ResponseChannel, UNDEFINED, UNDEFINED, 0);
      Send(InvAck, Directory, p, ResponseChannel, UNDEFINED, UNDEFINED, 0);
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case Proc_IS_D:
    switch msg.mtype
    case Inv:
      msg_processed := false;
      -- pstate := Proc_ISI_D;
      -- Send(InvAck, msg.fwd_to,  p, ResponseChannel, UNDEFINED, UNDEFINED, 0);
      -- Send(InvAck, Directory, p, ResponseChannel, UNDEFINED, UNDEFINED, 0);
    case FwdGetS:
      msg_processed := false;
    case FwdGetM:
      msg_processed := false;
    case Data:
      assert msg.ack_cnt = 0 "Error at Proc_IS_D: ack_cnt != 0";
      pstate := Proc_S;
      pvalue := msg.value;
    case EData:
      pstate := Proc_E;
      pvalue := msg.value;
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case Proc_IM_AD:
    switch msg.mtype
    case FwdGetS:
      msg_processed := false;
    case FwdGetM:
      msg_processed := false;
    case AckCnt:
      msg_processed := false;
      -- pcnt := pcnt + msg.ack_cnt;
      -- pstate := Proc_IM_A;
    case Data:
      if msg.src = Directory then -- data is from directory controller
        if msg.ack_cnt = 0 then
          pstate := Proc_M;
          undefine Procs[p].sharers;
        else
          assert (pcnt <= 0) "error at Proc_IM_AD, ack_cnt > 0.";
          pcnt :=  pcnt + msg.ack_cnt;
          if pcnt = 0 then
            pstate := Proc_M;
            undefine Procs[p].sharers;
          else
            pstate := Proc_IM_A;
          endif;
        endif;
      else -- data is from previous owner
        if IsLocalSharerListEmpty(p) then
          pstate := Proc_M;
          undefine Procs[p].sharers;
        else
          pstate := Proc_IM_A;
        endif;
      endif;
      pvalue := msg.value;
    case InvAck:
      msg_processed := false;
      -- pcnt := pcnt - 1;
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case Proc_IM_A:
    switch msg.mtype
    case Inv:
      pstate := Proc_I;
      Send(InvAck, msg.fwd_to, p, ResponseChannel, UNDEFINED, UNDEFINED, 0);
      Send(InvAck, Directory, p, ResponseChannel, UNDEFINED, UNDEFINED, 0);
      undefine pvalue;
    case FwdGetS:
      msg_processed := false;
    case FwdGetM:
      msg_processed := false;
    case AckCnt:
      pcnt := pcnt + msg.ack_cnt;
      if pcnt = 0 then
        pstate := Proc_M;
        undefine Procs[p].sharers;
      endif;
    case InvAck:
      pcnt := pcnt - 1;
      if pcnt = 0 then
        pstate := Proc_M;
        undefine Procs[p].sharers;
      endif;
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case Proc_S:
    switch msg.mtype
    case Inv:
      pstate := Proc_I;
      Send(InvAck, msg.fwd_to, p, ResponseChannel, UNDEFINED, UNDEFINED, 0);
      Send(InvAck, Directory, p, ResponseChannel, UNDEFINED, UNDEFINED, 0);
      undefine pvalue;
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case Proc_SM_AD:
    switch msg.mtype
    case Inv:
      pstate := Proc_IM_AD;
      Send(InvAck, msg.fwd_to, p, ResponseChannel, UNDEFINED, UNDEFINED, 0);
      Send(InvAck, Directory, p, ResponseChannel, UNDEFINED, UNDEFINED, 0);
    case FwdGetS:
      msg_processed := false;
    case FwdGetM:
      msg_processed := false;
    case AckCnt:
      msg_processed := false;
      -- pcnt := pcnt + msg.ack_cnt;
      -- pstate := Proc_SM_A;
    case Data:
      if msg.src = Directory then
        if msg.ack_cnt = 0 then
          pstate := Proc_M;
          undefine Procs[p].sharers;
        else
          assert (pcnt <= 0) "error at Proc_SM_AD, ack_cnt > 0.";
          pcnt :=  pcnt + msg.ack_cnt;
          if pcnt = 0 then
            pstate := Proc_M;
            undefine Procs[p].sharers;
          else
            pstate := Proc_SM_A;
          endif;
        endif;
      else
        if IsLocalSharerListEmpty(p) then
          pstate := Proc_M;
          undefine Procs[p].sharers;
        else
          pstate := Proc_SM_A;
        endif;
      endif;
      pvalue := msg.value;
    case InvAck:
      msg_processed := false;
      -- pcnt := pcnt - 1;
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case Proc_SM_A:
    switch msg.mtype
    case FwdGetS:
      msg_processed := false;
    case FwdGetM:
      msg_processed := false;
    case AckCnt:
      pcnt := pcnt + msg.ack_cnt;
      if pcnt = 0 then
        pstate := Proc_M;
        undefine Procs[p].sharers;
      endif;
    case InvAck:
      pcnt := pcnt - 1;
      if pcnt = 0 then
        pstate := Proc_M;
        undefine Procs[p].sharers;
      endif;
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case Proc_OM_AC:
    switch msg.mtype
    case FwdGetS:
      Send(FwdGetSAck, Directory,  p, ResponseChannel, UNDEFINED, UNDEFINED, 0);
      Send(Data, msg.fwd_to, p, DataChannel, pvalue, UNDEFINED, 0);
    case FwdGetM:
      if (p = msg.fwd_to) then
        pcnt   := pcnt + msg.ack_cnt;
        if pcnt = 0 then
          pstate := Proc_M;
          undefine Procs[p].sharers;
        else
          pstate := Proc_OM_A;
        endif;
        Send(FwdGetMAck, Directory,  p, ResponseChannel, UNDEFINED, msg.fwd_to, 0);
      else
        pstate := Proc_IM_AD;
        Send(Data, msg.fwd_to, p, DataChannel, pvalue, UNDEFINED, 0);
        Send(FwdGetMAck, Directory,  p, ResponseChannel, UNDEFINED, msg.fwd_to, 0);
      endif;
    case AckCnt:
      pcnt   := pcnt + msg.ack_cnt;
      pstate := Proc_OM_A;
    case InvAck:
        pcnt := pcnt - 1;
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case Proc_OM_A:
    switch msg.mtype
    case FwdGetS:
      msg_processed := false;
    case FwdGetM:
      msg_processed := false;
    case InvAck:
      pcnt := pcnt - 1;
      if pcnt = 0 then
        pstate := Proc_M;
        undefine Procs[p].sharers;
      endif;
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case Proc_EM_A:
    switch msg.mtype
    case FwdGetS:
      Send(FwdGetSAck, Directory,  p, ResponseChannel, UNDEFINED, UNDEFINED, 0);
      Send(Data, msg.fwd_to, p, DataChannel, pvalue, UNDEFINED, 0);
    case FwdGetM:
      if (p = msg.fwd_to) then
        pcnt := pcnt + msg.ack_cnt;
        if pcnt = 0 then 
          pstate := Proc_M;
          undefine Procs[p].sharers;
        else
          pstate := Proc_OM_A;
        endif;
        Send(FwdGetMAck, Directory,  p, ResponseChannel, UNDEFINED, p, 0);
      else
        pstate := Proc_IM_AD;
        Send(Data, msg.fwd_to, p, DataChannel, pvalue, UNDEFINED, 0);
        Send(FwdGetMAck, Directory,  p, ResponseChannel, UNDEFINED, msg.fwd_to, 0);
      endif;
    case AckCnt:
      pcnt := pcnt + msg.ack_cnt;
      if pcnt = 0 then
        pstate := Proc_M;
        undefine Procs[p].sharers;
      endif;
    case InvAck:
      pcnt := pcnt - 1;
      if pcnt = 0 then
        pstate := Proc_M;
        undefine Procs[p].sharers;
      endif;
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case Proc_M:
    switch msg.mtype
    case FwdGetS:
      pstate := Proc_O;
      Send(FwdGetSAck, Directory,  p, ResponseChannel, pvalue, UNDEFINED, 0);
      Send(Data, msg.fwd_to, p, DataChannel, pvalue, UNDEFINED, 0);
    case FwdGetM:
      pstate := Proc_I;
      Send(Data, msg.fwd_to, p, DataChannel, pvalue, UNDEFINED, 0);
      Send(FwdGetMAck, Directory,  p, ResponseChannel, UNDEFINED, UNDEFINED, 0);
      undefine pvalue;
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;
  
  case Proc_E:
    switch msg.mtype
    case FwdGetS:
      pstate := Proc_O;
      Send(FwdGetSAck, Directory,  p, ResponseChannel, UNDEFINED, UNDEFINED, 0);
      Send(Data, msg.fwd_to, p, DataChannel, pvalue, UNDEFINED, 0);
    case FwdGetM:
      pstate := Proc_I;
      Send(Data, msg.fwd_to, p, DataChannel, pvalue, UNDEFINED, 0);
      Send(FwdGetMAck, Directory,  p, ResponseChannel, UNDEFINED, UNDEFINED, 0);
      undefine pvalue;
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case Proc_O:
    switch msg.mtype
    case FwdGetS:
      Send(FwdGetSAck, Directory,  p, ResponseChannel, UNDEFINED, UNDEFINED, 0);
      Send(Data, msg.fwd_to, p, DataChannel, pvalue, UNDEFINED, 0);
    case FwdGetM:
      Send(Data, msg.fwd_to, p, DataChannel, pvalue, UNDEFINED, 0);
      Send(FwdGetMAck, Directory,  p, ResponseChannel, UNDEFINED, msg.fwd_to, 0);
      pstate := Proc_I;
      undefine pvalue;
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case Proc_MI_A:
    switch msg.mtype
    case FwdGetS:
      pstate := Proc_OI_A;
      Send(FwdGetSAck, Directory,  p, ResponseChannel, pvalue, UNDEFINED, 0);
      Send(Data, msg.fwd_to, p, DataChannel, pvalue, UNDEFINED, 0);
    case FwdGetM:
      pstate := Proc_II_A;
      Send(Data, msg.fwd_to, p, DataChannel, pvalue, UNDEFINED, 0);
      Send(FwdGetMAck, Directory,  p, ResponseChannel, UNDEFINED, UNDEFINED, 0);
    case PutAck:
      pstate := Proc_I;
      undefine pvalue;
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case Proc_OI_A:
    switch msg.mtype
    case FwdGetS:
      Send(FwdGetSAck, Directory,  p, ResponseChannel, pvalue, UNDEFINED, 0);
      Send(Data, msg.fwd_to, p, DataChannel, pvalue, UNDEFINED, 0);
    case FwdGetM:
      pstate := Proc_II_A;
      Send(Data, msg.fwd_to, p, DataChannel, pvalue, UNDEFINED, 0);
      Send(FwdGetMAck, Directory,  p, ResponseChannel, UNDEFINED, msg.fwd_to, 0);
    case PutAck:
      pstate := Proc_I;
      undefine pvalue;
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;
  
  case Proc_EI_A:
    switch msg.mtype
    case FwdGetS:
      -- pstate := Proc_SI_A;
      Send(FwdGetSAck, Directory,  p, ResponseChannel, UNDEFINED, UNDEFINED, 0);
      Send(Data, msg.fwd_to, p, DataChannel, pvalue, UNDEFINED, 0);
    case FwdGetM:
      pstate := Proc_II_A;
      Send(Data, msg.fwd_to, p, DataChannel, pvalue, UNDEFINED, 0);
      Send(FwdGetMAck, Directory,  p, ResponseChannel, UNDEFINED, msg.fwd_to, 0);
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
      Send(InvAck, Directory, p, ResponseChannel, UNDEFINED, UNDEFINED, 0);
    case PutAck:
      pstate := Proc_I;
      undefine pvalue;
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case Proc_II_A:
    switch msg.mtype
    case Inv:
      -- pstate := Proc_I;
      Send(InvAck, msg.fwd_to,  p, ResponseChannel, UNDEFINED, UNDEFINED, 0);
      Send(InvAck, Directory, p, ResponseChannel, UNDEFINED, UNDEFINED, 0);
      -- undefine pvalue;
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

    rule "O ==(store)==> M"
      p.state = Proc_O
    ==>
      Send(GetM, Directory, n, RequestChannel, UNDEFINED, UNDEFINED, 0);
      p.state := Proc_OM_AC;
    endrule;

    rule "O ==(evict)==> I"
      p.state = Proc_O
    ==>
      Send(PutO, Directory, n, RequestChannel, p.value, UNDEFINED, 0);
      p.state := Proc_OI_A;
    endrule;

    rule "E ==(store)==> M"
      p.state = Proc_E
    ==>
      Send(GetM, Directory, n, RequestChannel, p.value, n, 0);
      p.state := Proc_EM_A;
    endrule;

    rule "E ==(evict)==> I"
      p.state = Proc_E
    ==>
      Send(PutE, Directory, n, RequestChannel, UNDEFINED, UNDEFINED, 0);
      p.state := Proc_EI_A;
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

    rule "I ==(load)==> S/E"
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
  DirNode.ack_cnt := 0;
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
    undefine Procs[i].sharers;
  endfor;

  -- network initialization
  undefine Net;
endstartstate;

----------------------------------------------------------------------
-- Invariants
----------------------------------------------------------------------
--- Contriants for DirNode.owner
invariant "Directory in S/I state implies empty owner"
  (DirNode.state = Dir_I | DirNode.state = Dir_S)
    ->
      DirNode.owner = Directory;

invariant "Directory in M/O/E state implies owner exists"
  (DirNode.state = Dir_M | DirNode.state = Dir_O | DirNode.state = Dir_E)
    ->
      DirNode.owner != Directory;

--- Contriants for DirNode.sharers
invariant "Directory in M/E/I state implies empty sharer list"
  (DirNode.state = Dir_I | DirNode.state = Dir_E | DirNode.state = Dir_M)
    ->
      MultiSetCount(i: DirNode.sharers, true) = 0;

invariant "Directory in O/S state implies non-empty sharer list"
  (DirNode.state = Dir_S | DirNode.state = Dir_O)
    ->
      MultiSetCount(i: DirNode.sharers, true) != 0;

--- Contriants for value
invariant "Processor in S or E state implies the value match memory"
  Forall n : Proc Do	
    (DirNode.state = Dir_S & Procs[n].state = Proc_S) | (DirNode.state = Dir_E & Procs[n].state = Proc_E)
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