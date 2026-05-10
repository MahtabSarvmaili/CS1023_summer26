#include <stdio.h>

int main(void)
{
   char userInput[100];

   printf("Enter text: ");
   fgets(userInput, sizeof(userInput), stdin);

   printf(userInput);

   return 0;
}
