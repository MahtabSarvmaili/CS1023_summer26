#include <stdio.h>

void convertToUppercase(char *sPtr); // prototype


int main(void)
{
   char string[] = "print characters of a string"; 
    printf("%p\n", string);
   convertToUppercase(string); 
   printf("The string in uppercase is:\n%s\n", string);
   printf("%p\n", string);

   puts("");
}

void convertToUppercase(char *sPtr)
{
   while(*sPtr != '\0') { // loop until end of string
      if (*sPtr >= 'a' && *sPtr <= 'z') { // if character is lowercase
         *sPtr -= ('a' - 'A'); // convert to uppercase
      }

      sPtr++; // move to next character
   }
}