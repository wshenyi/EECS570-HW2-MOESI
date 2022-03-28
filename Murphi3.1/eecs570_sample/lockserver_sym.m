Const
	numClient: 10;

Type
	server_t : Record
		lock : boolean;
	End;
	client_t : Record
		link : boolean;
	End;
	client_n: ScalarSet(numClient);
 
Var
	server : server_t;
	client : Array[client_n] of client_t;
 
StartState
Begin
	server.lock := true;
	For c : client_n Do
		client[c].link := false;
	End;
End;
 
RuleSet c : client_n Do
	Rule "client connect"
		server.lock
	==>
	Begin
		client[c].link := true;
		server.lock    := false;
	End;
      
	Rule "client disconnect"
		client[c].link
	==>
	Begin
		client[c].link := false;
		server.lock    := true;
	End;
End;
 
Invariant "only one client at a time"
	-- !(client[0].link & client[1].link)
	ForAll c1 : client_n Do
		ForAll c2 : client_n Do
			-- c1 != c2 -> !client[c1].link | !client[c2].link
			c1 != c2 -> (!client[c1].link & !client[c2].link) | (client[c1].link & !client[c2].link) | (!client[c1].link & client[c2].link)
		End
	End;