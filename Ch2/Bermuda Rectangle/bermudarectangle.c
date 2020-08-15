#include <stdio.h>
#include <stdlib.h>
void go_south_east(int *lat, int *lon)
{
	*lat = *lat -1; 	//decrease latitude 
	*lon = *lon +1; 	//increase longitude  
	printf("lat = %i and lon =%i\n", lat, lon);
} 



int main (int argc, char argv[])
{
	int latitude = 32; 
	int longitude = -64; 

	go_south_east(&latitude, &longitude); 

	printf("Avast! Now at [%i, %i]\n", latitude, longitude);
	
	char string[] = "Cookies make\0 you fat";
	char *t = string; 
	printf("size of  ""turtles"" is %c\n", *string);
	printf("contents of t[0] is %c\t",(4[t]) );
 	printf("contents of t[2] is %c\n",(5[t]) );
	printf("size of *t = %i\n", sizeof(t) );

	char first_name[20]; 
	char last_name[20]; 
	printf("Enter first and last name: "); 
	gets(first_name); 
	printf("First: %s Last:%s\n", first_name, last_name); 
	return 0; 
}