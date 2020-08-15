// 10/08/2020    Head First C 
// Example Card Exercise 

#include <stdio.h>
#include <stdlib.h>

int main() 
{
	char card_name[3]; 
	int count = 0; 
	while(card_name[0] != 'X')
	{
	puts("Enter the card name: "); 
	scanf("%2s", card_name); 
	int val =0; 

	switch(card_name[0])
	{
		case 'K':  
		case 'Q': 
		case 'J': 
			val = 10; 
			break; 
		case 'A': 
			val = 11; 
		case 'X': 
			continue; 
			break; 
		default: 
		val = atoi(card_name); 
		if (val <1 || val>10)
		{
			puts("I dont understand that value!");
			continue; 
		}
	
	}
	printf("The card value is : %i\n", val); 


	if(val >=3 && val<=6)count++; 
	else if (val ==10 || val == 11) count--; 

	printf("Current Count: %i\n", count); 
	}	
	return 0; 
}