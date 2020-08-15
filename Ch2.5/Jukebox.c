#include <stdio.h>
#include <string.h>

char tracks[][80] = 
{
	"I left my heart in Havard Med School", 
	"Newark, Newark - a wonderful town", 
	"Dancing with a Dork", 
	"From here to maternity", 
	"The girl from Iwo Jima", 
};

void print_reverse(char *s)
{
	size_t len = strlen(s); 
	char *t = s + len -1;  

	while(t >= s)
	{
		printf("%c", *t); 

		t = t -1; 
	}
	puts(""); 
}


void find_track(char search_for[])
{
	printf("Searching for: %s\n", search_for );
	int i; 
	for(i=0; i<5; i++)
	{	
		if (strstr(tracks[i], search_for))
		{
			printf("Track %i: '%s'\n", i, (tracks[i]) );
		}
		// else
		// { 
		// 	continue; 
		// 	printf("No track found"); 
		// }
	}

}


int main(int argc, char argv[])
{
	char search_for[80]; 
	printf("Search for: "); 
	scanf("%79s", search_for); 
	find_track(search_for); 

	return 0; 
}