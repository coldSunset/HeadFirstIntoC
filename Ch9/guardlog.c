#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char* now()
{
	time_t t; 
	time(&t); 
	return asctime(localtime(&t)); 
}

/* master Control Program utility 
	Records guard patrol check-ins */ 

int main() 
{
	char comment[80]; 
	char cmd[120]; 
	char* timestring = NULL; 
	fgets(comment, 80, stdin);
	comment[strlen(comment)-1] =0;
	timestring = now(); 
	timestring[strlen(timestring)-1]=0;

	sprintf(cmd, "echo '%s %s' >> reports.log", comment, timestring); 
	puts("-----");
	puts(cmd); 
	puts("-----");
	system(cmd); 
	return 0; 
}