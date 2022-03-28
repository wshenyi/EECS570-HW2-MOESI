Var server_lock : boolean;
Var client0_link, client1_link : boolean;
 
StartState
Begin
	server_lock := true;
	client0_link := false;
	client1_link := false;
End;
 
Rule "client 0 connect"
	server_lock
==>
Begin
	client0_link := true;
	server_lock := false;
End;
      
Rule "client 1 connect"
	server_lock
==>
Begin
	client1_link := true;
	server_lock := false;
End;
 
Rule "client 0 disconnect"
	client0_link
==>
Begin
	client0_link := false;
    server_lock  := true;
End;
      
Rule "client 1 disconnect"
	client1_link
==>
Begin
	client1_link := false;
    server_lock  := true;
End;

Invariant "only one client at a time"
	server_lock | (!server_lock & ((client0_link & !client1_link) | (!client0_link & client1_link)))