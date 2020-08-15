#include <stdio.h> 

int main(int argc, char argv[])
{
	char masked_raider[] = "Alive"; 
	char *jimmy = masked_raider; 
	printf("Masked raider is %s, Jimmy is %s\n", masked_raider, jimmy);
	const char *dead_s = "DEAD!"; 

	for(int i=0; i<5; i++)
	{
		masked_raider[i] = dead_s[i]; 
	}

	printf("Masked Raider is %s, Jimmy is %s\n", masked_raider, jimmy);


	return 0; 
}