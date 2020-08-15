//Live Demo
#include <stdio.h>
#include <string.h>


int main () {
   const char haystack[20] = "TutorialsPoint";
   const char needle[10] = "Point";
   char *ret;

   ret = strstr(haystack, needle);

   printf("The substring is: %s\n", ret);
   printf("The ret value is : %p\n", *ret);
   printf("The array address: %p\n", *(haystack+9));
   if(ret) printf("this works");
   return(0);
}