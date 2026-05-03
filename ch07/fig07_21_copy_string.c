// Fig. 7.21: fig07_21.c
// Copying a string using array notation and pointer notation.
#include <stdio.h>
#include <string.h>
#define SIZE 10


void stringArray(void);
void copy1(char * const s1, const char * const s2); // prototype
void copy2(char *s1, const char *s2); // prototype
void copyBySubscript(char * const s1, const char * const s2);
void copyByPointer(char *s1, const char *s2); // prototype

int main(void)
{
   char string1[SIZE]; // create array string1
   char *string2 = "Hello"; // create a pointer to a string

   copy1(string1, string2);
   printf("string1 = %s\n", string1);

   char string3[SIZE]; // create array string3
   char string4[] = "Good Bye"; // create an array containing a string

   copy2(string3, string4);
   printf("string3 = %s\n", string3);

   printf("--------------------------------\n");
   copyBySubscript(string1, string2);
   printf("string1 = %s\n", string1);
   copyByPointer(string1, string2);
   printf("string1 = %s\n", string1);
   printf("--------------------------------\n");
   stringArray();
} 

// copy s2 to s1 using array notation
void copy1(char * const s1, const char * const s2)
{
   // loop through strings
   for (size_t i = 0; (s1[i] = s2[i]) != '\0'; ++i) {
      ; // do nothing in body                      
   }                                     
}

// copy s2 to s1 using pointer notation
void copy2(char *s1, const char *s2)
{
   // loop through strings
   for (; (*s1 = *s2) != '\0'; ++s1, ++s2) {
      ; // do nothing in body                
   }                               
} 


/**************************************************************************
 * (C) Copyright 1992-2015 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/
// copy s2 to s1 by subscript
void copyBySubscript(char * const s1, const char * const s2)
{
   for (size_t i=0; (s1[i] = s2[i]) !='\0'; ++i)
   {
      ; // do nothing in body
   }
}

// copy s2 to s1, copying the pointers using pointer arithmetic
void copyByPointer(char *s1, const char *s2)
{
   for (; (*s1 = *s2) != '\0'; ++s1, ++s2)
   {
      ; // do nothing in body
   }
}

void stringArray(void)
{
   char *strings[3] = {"Hello", "How are you", "Goodbye"};
   for (size_t i=0; i<3; ++i)
   {
      printf("the %zu-th string is %s\n", i, strings[i]);
      printf("the address of the %zu-th string is %p\n", i, &strings[i]);
      printf("the address of the first character of the %zu-th string is %p\n", i, &strings[i][0]);
      printf("the address of the 4th character of the %zu-th string is %p\n and the value of the 4th character is %c\n", i, &strings[i][0]+3, strings[i][3]);
      printf("the address to the last character of the %zu-th string is %p\n and the value of the last character is %c\n", i, &strings[i][0]+strlen(strings[i])-1, strings[i][strlen(strings[i])-1]);
   }
}