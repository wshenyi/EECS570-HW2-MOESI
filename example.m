
-- standard MSI protocol

---------------------------------------------------------------------------------
-- Constants---------------------------------------------------------------------
---------------------------------------------------------------------------------
const
	ProcCount: 2;			-- number of processors
	ValueCount:	2;			-- number of data values
	NumVCs: 4;				-- number of virtual channels
	RequestChannel: 0;		-- virtual channel #0
	ForwardChannel: 1;		-- virtual channel #1
	ResponseChannel: 2;		-- virtual channel #2
	OrderChannel: 3;		-- virtual channel #3
	NetMax: ProcCount*3; 	-- network capacity (infinite)
	

---------------------------------------------------------------------------------
-- Types-------------------------------------------------------------------------
---------------------------------------------------------------------------------
type
	Proc: scalarset(ProcCount);	  	-- unordered range of processors
	Value: scalarset(ValueCount); 	-- arbitrary values for tracking coherence
	Dir: enum { DirType };	  		-- need enumeration for IsMember calls
	Node: union { Dir , Proc };		-- track node type

	VCType: 0..NumVCs-1;
	AckCount: 0..ProcCount-1;

	-- define enum for message types
	MessageType: enum {	 
		GetS,		-- RequestChannel
		GetM,
		PutM,
		PutS,
		FwdGetS,	-- ForwardChannel
		FwdGetM,
		Inv,
		PutAck,		-- ResponseChannel
		Data,		
		InvAck,
		PutAckAck,  -- OrderChannel
		DataAck
	};

	-- define message
	Message:
		Record
			mtype: MessageType;
			src: Node;
			-- do not need a destination for verification; the destination is 
			-- indicated by which array entry in the Net the message is placed
			vc: VCType;
			val: Value;
			who: Node; 		-- tells procs which proc to forward data to
			ack: AckCount;	-- needed for Data messages to count expected Acks
		end;

	DirState:
		Record
			state: enum { -- directory controller states
				M_I,
				M_S,
				M_M,
				M_MS_D,
				M_MS_DP,
				M_MS_DA,
				M_XM_A,
				M_XS_A,
				M_I_P,
				M_S_P,
				M_M_P
			};
			owner: Node;	
			sharers: multiset [ProcCount] of Node;		
			val: Value; 
		end;

	ProcState:
		Record
			state: enum { -- cache controller states
				P_I,
				P_IS_D,
				P_IM_AD,
				P_IM_A,
				P_S,
				P_SM_AD,
				P_SM_A,
				P_M,
				P_MI_A,
				P_SI_A,
				P_II_A,
				P_MI_AA,
				P_MI_II_AA,
				P_MS_A,
				P_MI_SI_AA
			};
			val: Value;
			acks_needed: AckCount;
			acks_received: AckCount;
		end;

---------------------------------------------------------------------------------
-- Variables---------------------------------------------------------------------
---------------------------------------------------------------------------------
var
	DirNode: DirState;
	Procs: array [Proc] of ProcState;
	-- One multiset for each dest: messages arbitrarily reordered by multiset
	Net:   array [Node] of multiset [NetMax] of Message;		
	-- If a message not processed, placed in InBox, blocking that virtual channel
	InBox: array [Node] of array [VCType] of Message; 
	msg_processed: boolean;
	-- confirm that writes are not lost; would not exist in real hardware
	LastWrite: Value; 

---------------------------------------------------------------------------------
-- procedures--------------------------------------------------------------------
---------------------------------------------------------------------------------
procedure Send(mtype: MessageType;
				 dst: Node;
				 src: Node;
				 vc: VCType;
				 val: Value;
				 who: Node;
				 ack: AckCount;
			 );
var msg: Message;
begin
	Assert (MultiSetCount(i: Net[dst], true) < NetMax) "Too many messages";
	msg.mtype:= mtype;
	msg.src	 := src;
	msg.vc	 := vc;
	msg.val	 := val;
	msg.who  := who;
	msg.ack  := ack;
	MultiSetAdd(msg, Net[dst]);
end;

---------------------------------------------------------------------------------

procedure ErrorUnhandledMsg(msg: Message; n: Node);
begin
	error "Unhandled message type!";
end;

---------------------------------------------------------------------------------

procedure ErrorUnhandledState();
begin
	error "Unhandled state!";
end;

---------------------------------------------------------------------------------

procedure AddToSharersList(n: Node);
begin
	if MultiSetCount(i: DirNode.sharers, DirNode.sharers[i] = n) = 0
	then
		MultiSetAdd(n, DirNode.sharers);
	endif;
end;

---------------------------------------------------------------------------------

Function IsSharer(n: Node) : Boolean;
begin
	return MultiSetCount(i: DirNode.sharers, DirNode.sharers[i] = n) > 0
end;

---------------------------------------------------------------------------------

procedure RemoveFromSharersList(n: Node);
begin
	MultiSetRemovePred(i: DirNode.sharers, DirNode.sharers[i] = n);
end;

---------------------------------------------------------------------------------

-- Sends a message to all sharers except rqst
procedure SendInvReqToSharers(rqst: Node);
begin
	for n: Node do
		-- if it's a processor and is a sharer
		if (IsMember(n, Proc) &
				MultiSetCount(i: DirNode.sharers, DirNode.sharers[i] = n) != 0)
		then
			-- don't invalidate the requestor
			if n != rqst
			then 
				-- send invalidation from requestor to all other sharer procs
				Send(Inv, n, rqst, ForwardChannel, UNDEFINED, UNDEFINED, UNDEFINED)
			endif;
		endif;
	endfor;
end;

---------------------------------------------------------------------------------

-- memory controller is receiving a message
procedure DirReceive(msg: Message);
var cnt: 0..ProcCount;	-- for counting sharers
begin

	-- Debug output may be helpful:
	/* put "Dir receiving "; put msg.mtype; put " from "; put msg.src; put ", state ->"; */

	-- pre-calculate the sharer count here
	cnt := MultiSetCount(i: DirNode.sharers, true);

	-- default to 'processing' message,	set to false if stalling
	msg_processed := true;

	switch DirNode.state
	case M_I:
		switch msg.mtype
		case GetS:
			DirNode.state := M_XS_A;
			AddToSharersList(msg.src);
			-- existing sharers can be ignored since the data is read-only
			Send(Data, msg.src, DirType, ResponseChannel, DirNode.val, UNDEFINED, 0);
		case GetM:
			DirNode.state := M_XM_A;
			DirNode.owner := msg.src;
			Send(Data, msg.src, DirType, ResponseChannel, DirNode.val, UNDEFINED, cnt);
		case PutS:
			DirNode.state := M_I_P;
			Send(PutAck, msg.src, DirType, ResponseChannel, UNDEFINED, UNDEFINED, UNDEFINED);
		case PutM:
			assert (msg.src != DirNode.owner) "PutM from owner";
			DirNode.state := M_I_P;
			Send(PutAck, msg.src, DirType, ResponseChannel, UNDEFINED, UNDEFINED, UNDEFINED);
		else
			ErrorUnhandledMsg(msg, DirType);
		endswitch;

	case M_S:
		switch msg.mtype
		case GetS:
			DirNode.state := M_XS_A;
			AddToSharersList(msg.src);
			-- existing sharers can be ignored since the data is read-only
			Send(Data, msg.src, DirType, ResponseChannel, DirNode.val, UNDEFINED, 0);
		case GetM:
			DirNode.state := M_XM_A;
			if IsSharer(msg.src) then -- don't need to wait for yourself to Ack
				Send(Data, msg.src, DirType, ResponseChannel, DirNode.val, UNDEFINED, cnt-1);
			else
				Send(Data, msg.src, DirType, ResponseChannel, DirNode.val, UNDEFINED, cnt);
			endif;
			SendInvReqToSharers(msg.src);
			undefine DirNode.sharers;
			DirNode.owner := msg.src;
		case PutS:
			Send(PutAck, msg.src, DirType, ResponseChannel, UNDEFINED, UNDEFINED, UNDEFINED);
			if IsSharer(msg.src) then -- not necessarily a sharer
				if cnt = 1 then
					DirNode.state := M_I_P;
				else
					DirNode.state := M_S_P;
				endif;
				RemoveFromSharersList(msg.src);
			else
				DirNode.state := M_S_P;
			endif;
		case PutM:
			assert (msg.src != DirNode.owner) "PutM from owner";
			RemoveFromSharersList(msg.src);
			Send(PutAck, msg.src, DirType, ResponseChannel, UNDEFINED, UNDEFINED, UNDEFINED);
			DirNode.state := M_S_P;
		else
			ErrorUnhandledMsg(msg, DirType);
		endswitch;

	case M_M:
		assert (!IsUnDefined(DirNode.owner)) "owner undefined";
		switch msg.mtype
		case GetS:
			DirNode.state := M_MS_DA;
			AddToSharersList(msg.src);
			AddToSharersList(DirNode.owner);
			Send(FwdGetS, DirNode.owner, DirType, ForwardChannel, UNDEFINED, msg.src, UNDEFINED);
			undefine DirNode.owner;
		case GetM:
			Send(FwdGetM, DirNode.owner, DirType, ForwardChannel, UNDEFINED, msg.src, UNDEFINED);
			DirNode.owner := msg.src;
			DirNode.state := M_XM_A;
		case PutS:
			Send(PutAck, msg.src, DirType, ResponseChannel, UNDEFINED, UNDEFINED, UNDEFINED);
			DirNode.state := M_M_P;
		case PutM:
			if DirNode.owner = msg.src then
				DirNode.val := msg.val;
				LastWrite := DirNode.val;
				undefine DirNode.owner;
				DirNode.state := M_I_P;
			else
				DirNode.state := M_M_P;
			endif;
			Send(PutAck, msg.src, DirType, ResponseChannel, UNDEFINED, UNDEFINED, UNDEFINED);
		else
			ErrorUnhandledMsg(msg, DirType);
		endswitch;

	case M_MS_D:
		switch msg.mtype
		case GetS:
			msg_processed := false;
		case GetM:
			msg_processed := false;
		case PutS:
			RemoveFromSharersList(msg.src);
			Send(PutAck, msg.src, DirType, ResponseChannel, UNDEFINED, UNDEFINED, UNDEFINED);
			DirNode.state := M_MS_DP
		case PutM:
			RemoveFromSharersList(msg.src);
			Send(PutAck, msg.src, DirType, ResponseChannel, UNDEFINED, UNDEFINED, UNDEFINED);
			DirNode.state := M_MS_DP
		case Data:
			if cnt > 0 then
				DirNode.state := M_S;
				DirNode.val := msg.val;
				LastWrite := DirNode.val;
			else
				DirNode.state := M_I;
				DirNode.val := msg.val;
				LastWrite := DirNode.val;
			endif;
		else
			ErrorUnhandledMsg(msg, DirType);
		endswitch;

	case M_XM_A:
		switch msg.mtype
		case DataAck:
			DirNode.state := M_M;
		else
			msg_processed := false;
		endswitch;

	case M_MS_DP:
		switch msg.mtype
		case PutAckAck:
			DirNode.state := M_MS_D;
		else
			msg_processed := false;
		endswitch;

	case M_MS_DA:
		switch msg.mtype
		case DataAck:
			DirNode.state := M_MS_D;
		else
			msg_processed := false;
		endswitch;

	case M_XS_A:
		switch msg.mtype
		case DataAck:
			DirNode.state := M_S;
		else
			msg_processed := false;
		endswitch;

	case M_I_P:
		switch msg.mtype
		case PutAckAck:
			DirNode.state := M_I;
		else
			msg_processed := false;
		endswitch;

	case M_S_P:
		switch msg.mtype
		case PutAckAck:
			if cnt > 0 then
				DirNode.state := M_S;
			else
				DirNode.state := M_I;
			endif;
		else
			msg_processed := false;
		endswitch;

	case M_M_P:
		switch msg.mtype
		case PutAckAck:
			DirNode.state := M_M;
		else
			msg_processed := false;
		endswitch;

	else
		ErrorUnhandledState();
	endswitch; 
	
	/* put DirNode.state; */
end;

---------------------------------------------------------------------------------

procedure ProcReceive(msg: Message; p: Proc);
begin

	/* put "Proc "; put p; put " receiving "; put msg.mtype; put " from "; put msg.src;  put ", state ->"; */ 

	-- default to 'processing' message.	set to false otherwise
	msg_processed := true;

	alias pstate: Procs[p].state do
	alias pval: Procs[p].val do
	alias packs_needed: Procs[p].acks_needed do
	alias packs_received: Procs[p].acks_received do

	switch pstate
	case P_I:
		-- processor shouldn't receive any messages when in Invalid state
		ErrorUnhandledMsg(msg, p);

	case P_IS_D:
		switch msg.mtype
		case Inv:
			msg_processed := false;
		case Data:
			if msg.src != DirType then
				Send(DataAck, DirType, p, OrderChannel, UNDEFINED, UNDEFINED, UNDEFINED);
			else
				assert (msg.ack = 0) "Non-zero ACKs";
			endif;
			Send(DataAck, msg.src, p, OrderChannel, UNDEFINED, UNDEFINED, UNDEFINED);
			pstate := P_S;
			pval := msg.val;
		else
			ErrorUnhandledMsg(msg, p);
		endswitch;

	case P_IM_AD:
		switch msg.mtype
		case FwdGetS:
			msg_processed := false;
		case FwdGetM:
			msg_processed := false;
		case Data:
			if msg.src = DirType then -- data is from directory controller
				if msg.ack = 0 then -- no sharers, we can modify
					Send(DataAck, msg.src, p, OrderChannel, UNDEFINED, UNDEFINED, UNDEFINED);
					pstate := P_M;
				else -- wait on ACKs
					if msg.ack = packs_received then -- already received OoO ACKs
						Send(DataAck, DirType, p, OrderChannel, UNDEFINED, UNDEFINED, UNDEFINED);
						packs_needed := 0;
						packs_received := 0;
						pstate := P_M;
					else
						pstate := P_IM_A;
						packs_needed := msg.ack;
					endif;
				endif;
			else -- data is from another processor
				Send(DataAck, msg.src, p, OrderChannel, UNDEFINED, UNDEFINED, UNDEFINED);
				Send(DataAck, DirType, p, OrderChannel, UNDEFINED, UNDEFINED, UNDEFINED);
				packs_needed := 0;
				packs_received := 0;
				pstate := P_M;
			endif;
			pval := msg.val;
		case InvAck:
			packs_received := packs_received + 1;
		else
			ErrorUnhandledMsg(msg, p);
		endswitch;

	case P_IM_A:
		switch msg.mtype
		case FwdGetS:
			msg_processed := false;
		case FwdGetM:
			msg_processed := false;
		case InvAck:
			packs_received := packs_received + 1;
			if packs_received = packs_needed
			then
				Send(DataAck, DirType, p, OrderChannel, UNDEFINED, UNDEFINED, UNDEFINED);
				packs_needed := 0;
				packs_received := 0;
				pstate := P_M;
			endif;
		else
			ErrorUnhandledMsg(msg, p);
		endswitch;

	case P_S:
		switch msg.mtype
		case Inv:
			pstate := P_I;
			Send(InvAck, msg.src, p, ResponseChannel, UNDEFINED, UNDEFINED, UNDEFINED);
			undefine pval;
		else
			ErrorUnhandledMsg(msg, p);
		endswitch;

	case P_SM_AD:
		switch msg.mtype
		case FwdGetS:
			msg_processed := false;
		case FwdGetM:
			msg_processed := false;
		case Inv:
			pstate := P_IM_AD;
			Send(InvAck, msg.src, p, ResponseChannel, UNDEFINED, UNDEFINED, UNDEFINED);
		case Data:
			if msg.src = DirType  then -- data is from directory controller
				if msg.ack = 0 then -- no sharers, we can modify
					Send(DataAck, msg.src, p, OrderChannel, UNDEFINED, UNDEFINED, UNDEFINED);
					pstate := P_M;
				else -- wait on ACKs
					if msg.ack = packs_received then -- already received OoO ACKs
						Send(DataAck, msg.src, p, OrderChannel, UNDEFINED, UNDEFINED, UNDEFINED);
						packs_needed := 0;
						packs_received := 0;
						pstate := P_M;
					else
						pstate := P_SM_A;
						packs_needed := msg.ack;
					endif;
				endif;
			else -- data is from another processor
				Send(DataAck, msg.src, p, OrderChannel, UNDEFINED, UNDEFINED, UNDEFINED);
				Send(DataAck, DirType, p, OrderChannel, UNDEFINED, UNDEFINED, UNDEFINED);
				packs_needed := 0;
				packs_received := 0;
				pstate := P_M;
			endif;
			pval := msg.val;
		case InvAck:
			packs_received := packs_received + 1;
		else
			ErrorUnhandledMsg(msg, p);
		endswitch;

	case P_SM_A:
		switch msg.mtype
		case FwdGetS:
			msg_processed := false;
		case FwdGetM:
			msg_processed := false;
		case InvAck:
			packs_received := packs_received + 1;
			if packs_received = packs_needed
			then
				Send(DataAck, DirType, p, OrderChannel, UNDEFINED, UNDEFINED, UNDEFINED);
				packs_needed := 0;
				packs_received := 0;
				pstate := P_M;
			endif;
		else
			ErrorUnhandledMsg(msg, p);
		endswitch;

	case P_M:
		switch msg.mtype
		case FwdGetS:
			pstate := P_MS_A;
			Send(Data, DirType, p, ResponseChannel, pval, UNDEFINED, UNDEFINED);
			Send(Data, msg.who, p, ResponseChannel, pval, UNDEFINED, 0);
		case FwdGetM:
			pstate := P_MI_AA;
			Send(Data, msg.who, p, ResponseChannel, pval, UNDEFINED, 0);
			undefine pval;
		else
			ErrorUnhandledMsg(msg, p);
		endswitch;

	case P_MI_A:
		switch msg.mtype
		case FwdGetS:
			pstate := P_MI_SI_AA;
			Send(Data, DirType, p, ResponseChannel, pval, UNDEFINED, UNDEFINED);
			Send(Data, msg.who, p, ResponseChannel, pval, UNDEFINED, 0);
		case FwdGetM:
			pstate := P_MI_II_AA;
			Send(Data, msg.who, p, ResponseChannel, pval, UNDEFINED, 0);
		case PutAck:
			pstate := P_I;
			Send(PutAckAck, DirType, p, OrderChannel, UNDEFINED, UNDEFINED, UNDEFINED);
			undefine pval;
		else
			ErrorUnhandledMsg(msg, p);
		endswitch;

	case P_SI_A:
		switch msg.mtype
		case Inv:
			pstate := P_II_A;
			Send(InvAck, msg.src, p, ResponseChannel, UNDEFINED, UNDEFINED, UNDEFINED);
		case PutAck:
			pstate := P_I;
			Send(PutAckAck, DirType, p, OrderChannel, UNDEFINED, UNDEFINED, UNDEFINED);
			undefine pval;
		else
			ErrorUnhandledMsg(msg, p);
		endswitch;

	case P_II_A:
		switch msg.mtype
		case PutAck:
			pstate := P_I;
			Send(PutAckAck, DirType, p, OrderChannel, UNDEFINED, UNDEFINED, UNDEFINED);
			undefine pval;
		else
			ErrorUnhandledMsg(msg, p);
		endswitch;

	case P_MI_AA:
		switch msg.mtype
		case PutAck:
			msg_processed := false;
		case DataAck:
			pstate := P_I;
			undefine pval;
		else
			ErrorUnhandledMsg(msg, p);
		endswitch;

	case P_MI_II_AA:
		switch msg.mtype
		case PutAck:
			msg_processed := false;
		case DataAck:
			pstate := P_II_A;
		else
			ErrorUnhandledMsg(msg, p);
		endswitch;

	case P_MS_A:
		switch msg.mtype
		case Inv:
			msg_processed := false;
		case PutAck:
			msg_processed := false;
		case DataAck:
			pstate := P_S;
		else
			ErrorUnhandledMsg(msg, p);
		endswitch;

	case P_MI_SI_AA:
		switch msg.mtype
		case Inv:
			msg_processed := false;
		case PutAck:
			msg_processed := false;
		case DataAck:
			pstate := P_SI_A;
		else
			ErrorUnhandledMsg(msg, p);
		endswitch;

	else
		ErrorUnhandledState();
	endswitch;
	
	/* put Procs[p].state; */
	
	endalias;
	endalias;
	endalias;
	endalias;
end;

---------------------------------------------------------------------------------
-- Rules-------------------------------------------------------------------------
---------------------------------------------------------------------------------

-- Processor actions (affecting coherency)
ruleset n: Proc do
	alias p: Procs[n] do

	rule "Processor in Invalid state, requesting to load value"
		(p.state = P_I)
	==>
		Send(GetS, DirType, n, RequestChannel, UNDEFINED, UNDEFINED, UNDEFINED);
		p.state := P_IS_D;
		/* put n; put " sending GetS, state ->"; put p.state; */
	endrule;

	ruleset v: Value do
		rule "Processor in Invalid state, requesting to store value"
			(p.state = P_I)
		==>
			Send(GetM, DirType, n, RequestChannel, UNDEFINED, UNDEFINED, UNDEFINED);
			p.state := P_IM_AD;
			/* put n; put " sending GetM, state ->"; put p.state; */
		endrule;
	endruleset;

	ruleset v: Value do
		rule "Processor in Shared state, requesting to store value"
			(p.state = P_S)
		==>
			Send(GetM, DirType, n, RequestChannel, UNDEFINED, UNDEFINED, UNDEFINED);
			p.state := P_SM_AD;
			/* put n; put " sending GetM, state ->"; put p.state; */
		endrule;
	endruleset;

	rule "Processor in Shared state, evicting value"
		(p.state = P_S)
	==>
		Send(PutS, DirType, n, RequestChannel, UNDEFINED, UNDEFINED, UNDEFINED);
		p.state := P_SI_A;
		/* put n; put " sending PutS, state ->"; put p.state; */
	endrule;

	rule "Processor in Modified state, evicting value"
		(p.state = P_M)
	==>
		Send(PutM, DirType, n, RequestChannel, p.val, UNDEFINED, UNDEFINED);
		p.state := P_MI_A;
		/* put n; put " sending PutM, state ->"; put p.state; */
	endrule;

	endalias;
endruleset;

---------------------------------------------------------------------------------

-- Message delivery rules
ruleset n: Node do
	-- choose a random message index for this Node
	choose midx: Net[n] do
		alias chan: Net[n] do
		alias msg: chan[midx] do
		alias box: InBox[n] do

		-- Pick a random message in the network and deliver it
		rule "Receive-net"
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
				-- The node refused the message, put in InBox to block the VC.
				box[msg.vc] := msg;
			endif;
		
			MultiSetRemove(midx, chan);
		
		endrule;
	
		endalias
		endalias;
		endalias;
	endchoose;	

	-- Try to deliver a message from a blocked VC; perhaps node can handle it now
	ruleset vc: VCType do
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

---------------------------------------------------------------------------------
-- Startstate--------------------------------------------------------------------
---------------------------------------------------------------------------------
startstate

	-- mem node initialization
	For v: Value do
		DirNode.state := M_I;
		undefine DirNode.owner;
		undefine DirNode.sharers;
		DirNode.val := v;
	endfor;
	LastWrite := DirNode.val;
	
	-- processor initialization
	for i: Proc do
		Procs[i].state := P_I;
		undefine Procs[i].val;
		Procs[i].acks_needed := 0;
		Procs[i].acks_received := 0;
	endfor;

	-- network initialization
	undefine Net;
endstartstate;

---------------------------------------------------------------------------------
-- Invariants--------------------------------------------------------------------
---------------------------------------------------------------------------------

invariant "Invalid implies empty owner"
	DirNode.state = M_I
		->
			IsUndefined(DirNode.owner);

---------------------------------------------------------------------------------

invariant "Values in memory matches value of last write, when invalid"
		 DirNode.state = M_I
		->
			DirNode.val = LastWrite;

---------------------------------------------------------------------------------
	
invariant "Value is undefined while invalid"
	Forall n : Proc Do	
		 Procs[n].state = P_I
		->
			IsUndefined(Procs[n].val)
	end;
	
---------------------------------------------------------------------------------

invariant "Shared implies non-empty sharer list"
	DirNode.state = M_S
		->
			MultiSetCount(i: DirNode.sharers, true) > 0;

---------------------------------------------------------------------------------

invariant "Modified implies empty sharer list"
	DirNode.state = M_M
		->
			MultiSetCount(i: DirNode.sharers, true) = 0;

---------------------------------------------------------------------------------

invariant "Modified implies owner exists"
	DirNode.state = M_M
		->
			!IsUndefined(DirNode.owner);

---------------------------------------------------------------------------------

invariant "Invalid implies empty sharer list"
	DirNode.state = M_I
		->
			MultiSetCount(i: DirNode.sharers, true) = 0;

---------------------------------------------------------------------------------

invariant "Values in memory matches value of last write, when shared or invalid"
	Forall n : Proc Do	
		 DirNode.state = M_S | DirNode.state = M_I
		->
			DirNode.val = LastWrite
	end;

---------------------------------------------------------------------------------

invariant "Values in shared state match memory"
	Forall n : Proc Do	
		 DirNode.state = M_S & Procs[n].state = P_S
		->
			DirNode.val = Procs[n].val
	end;

---------------------------------------------------------------------------------

invariant "Ack counters should be 0 when not waiting for Acks"
	Forall n : Proc Do	
		 Procs[n].state != P_IM_AD & Procs[n].state != P_IM_A & Procs[n].state != P_SM_AD & Procs[n].state != P_SM_A
		->
			Procs[n].acks_needed = 0 & Procs[n].acks_received = 0
	end;

---------------------------------------------------------------------------------

invariant "If waiting for Data, acks_needed=0"
	Forall n : Proc Do	
		 Procs[n].state = P_IM_AD | Procs[n].state = P_SM_AD
		->
			Procs[n].acks_needed = 0
	end;

---------------------------------------------------------------------------------

invariant "If waiting for Acks, acks_received < acks_needed"
	Forall n : Proc Do	
		 Procs[n].state = P_IM_A | Procs[n].state = P_SM_A
		->
			Procs[n].acks_needed > Procs[n].acks_received
	end;