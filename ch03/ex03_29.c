#include <stdio.h>

void printPattern(void);

int main( void )
{
   unsigned int row = 10; // initialize row 

   while ( row >= 1 ) { // loop until row < 1 
      unsigned int column = 1; // set column to 1 as iteration begins 

      while ( column <= 10 ) { // loop 10 times 
         // condition ? value_if_true : value_if_false
         printf( "%s", row % 2 ? "<": ">" ); // output 
         ++column; // increment column 
      } // end inner while 

      --row; // decrement row 
      puts( "" ); // begin new output line 
   } // end outer while 
   printPattern();
   return 0;
} // end function main 



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



void printPattern(void)
{
   // if the row is unsigned this program will fall in the infinite loop because row will never be less than 0. 
   int row;
   for (row=0; row<=10; row++)
   {
      unsigned int column = 0;
      while (column <=row)
      {
         printf("%s", row %2 ? "xo \n" : "...\n");
         column=column*2+1;
      }
         
   }
}