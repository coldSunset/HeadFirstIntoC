#include <stdio.h> 
#include <arpa/inet.h> 
#include <errno.h> 
#include <string.h> 
#include <stdlib.h>
#include <sys/socket.h> 
#include <unistd.h>
#include <signal.h> 

#include "error.h"
#include "catchsignal.h"
#include "readin.h"
#include "serverproc.h"

#define PORT 30000
#define DEPTH 10

int listener_d; 

char *server_resp[] = {
"Internet Knock-Knock Protocol Server\r\nVersion 1.0\r\nKnock!Knock!\r\n> ", 
"Oscar \r\n",
"Oscar sill question, you get a silly answer\r\n", 
};
char *client_resp[] = {
"Who's there?\r\n", 
"Oscar who? \r\n",
};


int main(int argc, char** argv)
{

	if(catch_signal(SIGINT, handle_shutdown) == -1)
		error("Can't set the interrupt handler");

	//open socket 
	listener_d = open_listener_socket();
	bind_to_port(listener_d, PORT);  
	//listen to client
	if(listen(listener_d, DEPTH) == -1);
		puts("Can't Listen");

	struct sockaddr_storage client_addr; 
	unsigned int address_size = sizeof(client_addr); 
	puts("waiting for connection"); 
	char buf[255]; 
	int idx =0; 

	// pid_t pid = fork(); 
	// if(pid == -1)
	// 	error("Can't fork process"); 
while(1) //You need to loop the accept/begin talking section  
{

	int connect_d = accept(listener_d, (struct sockaddr *)&client_addr, &address_size); 
	if(connect_d == -1)
		error("Can't open secondary socket"); 

	if(!fork()) //child process
	{
		close(listener_d);
  	if(say(connect_d, server_resp[idx]) != -1)
  	{
  		read_in(connect_d, buf, sizeof(buf)); 
  		if(strncasecmp(client_resp[idx++], buf, 12))
  			say(connect_d, "You should say 'Who's there?'!\r\n");
  		else 
  		{
  			if(say(connect_d, server_resp[idx]) != -1)
  			{
  				read_in(connect_d, buf, sizeof(buf)); 
  				if(strncasecmp(client_resp[idx++], buf, 10))
  					say(connect_d, "You should say 'Oscar who?'!\r\n");
  				else 
  					say(connect_d, server_resp[idx]); 
  			}
  		}
  	}
  	 close(connect_d);
  	 exit(0); 

    }
	close(connect_d); 
}

	return 0; 
}