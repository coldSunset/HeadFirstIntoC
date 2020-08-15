#include <stdio.h> 
#include <stdlib.h>

int global_var; 
int global_var2; 
int main (int argc, char argv[])
{
	int stack_var;
	int stack_var2;  

	printf("The address of global_var is : %p\t and global_var2: %p\n", &global_var, &global_var2);
	printf("The address of stack_var is : %p\t and stack_var2: %p\n", &stack_var, &stack_var2);
	return 0; 
}