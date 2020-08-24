#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct island
{
	char *name; 
	char *opens; 
	char *closes; 
	struct island *next; 
} island; 

island amity = {"Amity", "09:00", "17:00", NULL}; 
island craggy = {"Craggy","09:00", "17:00", NULL}; 
island isla_nublar = {"Isla Nublar", "09:00", "17:00", NULL}; 
island shutter = {"Shutter", "09:00","17:00", NULL}; 

void display(island *start)
{
	island *i = start; 
	for(int j=1; i != NULL; j++, i = i->next)
	{
		printf("Destination %i ",j );
		printf("Name: %s open: %s-%s\n", i->name, i->opens,i->closes);	
	}
}

island* create(char *name)
{
	island i* = malloc(sizeof(island)); 
	i->name = strdup(name); 
	i->opens = "09:00"; 
	i->closes = "17:00"; 
	i-.next	= NULL; 
	return i; 
}

int main()
{
//linking the data 
 amity.next = &craggy; 
 craggy.next =&isla_nublar; 
 isla_nublar.next = &shutter; 
 display(&amity); 
//inserting values into the list
 island skull = {"Skull", "09:00", "17:00", NULL}; 
 isla_nublar.next = &skull; 
 skull.next = &shutter;
 printf("\n\n"); 
 display(&craggy); 
	return 0; 
}