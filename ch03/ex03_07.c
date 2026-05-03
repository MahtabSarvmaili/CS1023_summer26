// raise x to the y power 
#include <stdio.h>
#include <math.h>

double raiseToPower(double x, double y);
unsigned int raiseToPowerFloat(unsigned int x, unsigned int y);


int main( void )
{
   printf( "%s", "Enter first integer: " );
   unsigned int x; 
   scanf( "%u", &x ); // read value for x from user 
   printf( "%s", "Enter second integer: " );
   unsigned int y; 
   scanf( "%u", &y ); // read value for y from user 

   unsigned int i = 1; 
   unsigned int power = 1; // set power 

   // while ( i <= y ) { // loop while i is less than or equal to y 
   //    power *= x; // multiply power by x 
   //    ++i; // increment i 
   // } // end while                                        

   // printf( "%u\n", power ); // display power 

   // // using the defined function to calculate power
   // double result = raiseToPower(x, y);

   // printf("The result of %u raised to the power of %u is: %.8f\n", x, y, result);
   unsigned int resultFloat = raiseToPowerFloat(x, y);
   printf("the results of %u raised to the power of %u using the function we defined is: %u\n", x, y, resultFloat);
} // end main function 


/**************************************************************************
 * (C) Copyright 1992-2013 by Deitel & Associates, Inc. and               *
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


double raiseToPower(double x, double y)
{
   return pow(x, y);
}


unsigned int raiseToPowerFloat(unsigned int x, unsigned int y){
   unsigned int result = 1;
   unsigned int i = 0;
   while (i < y){
      result *=x;
      ++i;
   }
   return result;
}