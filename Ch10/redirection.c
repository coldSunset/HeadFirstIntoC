#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

const char* path = "/usr/bin/python3";

void error(char* msg)
{
	fprintf(stderr, "%s: %s\n",msg, strerror(errno));
	exit(1); 
}

int main(int argc, char* argv[])
{
	char *phrase = argv[1]; 
	char *vars[] = {"RSS_FEED=https://rss.msn.com/en-au/", NULL}; 
	FILE *f = fopen("stories.txt", "w"); 
	int descriptor = fileno(f); 

	if(!f)
	{
		error("Can't open stories .txt"); 
	}

	pid_t pid = fork(); 
	if(pid == -1)
	{
		error("Can't fork process"); 
	}
	if(!pid)
	{
		if(dup2(fileno(f), 1) == -1)
		{
			error("Can't redirect Standard Output"); 
		}
		if(execle(path, path, "./rssgossip.py", phrase, NULL, vars) == -1)
		{
			error("Can't run script"); 
		}
	}

	int pid_status; 
	if(waitpid(pid, &pid_status, 0) == -1); 
	{
		error("Error waiting for child process");
	}

	if(WEXITSTATUS(pid_status))
		puts("Error status non-zero"); 

	return 0; 
}
