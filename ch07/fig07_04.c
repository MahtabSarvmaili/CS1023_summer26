// Fig. 7.4: fig07_04.c
// Using the & and * pointer operators.
#include <stdio.h>
void printArray(int array[], size_t size);
void ModiyArray(int* a, int* b);
void testStatic(void);

void printArray(int array[], size_t size)
{
    printf("Elements of the array: ");
    for (size_t i=0; i<size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}


int main(void)
{
       int array[5] ={0}; 
       printArray(array, 5);
       ModiyArray(&array[0], &array[1]); // passing the address of the first two elements of the array to the function
       printArray(array, 5);
       int a = 10;
       int b = 30;

       printf("Before modifying a and b: a = %d, b = %d\n", a, b);
       ModiyArray(&a, &b); // passing the address of a and b to the function
       printf("After modifying a and b: a = %d, b = %d\n", a, b);
       testStatic();
       testStatic(); // call again to see the effect of static storage duration
//    int a = 7;
//    int *aPtr = &a; // set aPtr to the address of a

//    printf("The address of a is %p"
//           "\nThe value of aPtr is %p", &a, aPtr);

//    printf("\n\nThe value of a is %d"   
//           "\nThe value of *aPtr is %d", a, *aPtr);

//    printf("\n\nShowing that * and & are complements of "
//           "each other\n&*aPtr = %p"   
//           "\n*&aPtr = %p\n", &*aPtr, *&aPtr);
   

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



void ModiyArray(int* a, int* b)
{
       *a += 5; // this will modify the value of a in the caller function
       *b += 5; // this will modify the value of b in the caller function
}

void testStatic(void)
{
       static int array[5] = {0}; // this array will retain its value between function calls
       printf("Elements of the static array: ");
       for (size_t i=0; i<5; i++)
       {
              printf("%d ", array[i]);
              array[i] += 9; // this will modify the value of the array in the caller function
       }
       printArray(array, 5);
}