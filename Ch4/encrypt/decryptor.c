#include "decrypt.h" 

void decrypt(char *message) 
{
	char c; 
	while(*message)
	{
		*message = *message ^31; 
		message ++; 
	}
}