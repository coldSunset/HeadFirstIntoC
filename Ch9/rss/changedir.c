#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

const char* PATH = "/cygdrive/c/cygwin64/bin/python3.8.exe";


int main()
{	puts(PATH); 
	if(chdir(PATH) == -1)
		fprintf(stderr, "Can't run script: %s\n", strerror(errno));  

	return 0; 
}