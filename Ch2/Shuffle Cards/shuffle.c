#include <stdio.h>

int main (int argc, char argv[])
{
	char *cards = "JQK";
	printf("deck is currently showing %s\n", cards); 
	char a_card = cards[2]; // a_card = 'K' 
	cards[2] = cards[1]; // "JQQ"
	printf("deck is currently showing %s\n", cards); 



	return 0; 
}