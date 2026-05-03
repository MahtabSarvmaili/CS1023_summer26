// Fig. 3.6: fig03_06.c
// Class average program with counter-controlled iteration
#include <stdio.h>

double calcAverage(void);

// function main begins program execution
int main( void )
{
   // calling the function to calculate the average
   double average = calcAverage();
    printf("Class average is %.2f\n", average);


   // writing the logic in the main function
   unsigned int counter; // number of grade to be entered next
   int grade; // grade value
   int total; // sum of grades entered by user
   int average; // average of grades
   
   // initialization phase
   total = 0; // initialize total
   counter = 1; // initialize loop counter
   
   // processing phase
   while ( counter <= 10 ) { // loop 10 times
      printf( "%s", "Enter grade: " ); // prompt for input
      scanf( "%d", &grade ); // read grade from user
      total = total + grade; // add grade to total
      counter = counter + 1; // increment counter
   } // end while
   
   // termination phase
   average = total / 10; // integer division

   printf( "Class average is %d\n", average ); // display result
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


double calcAverage(void){
   int counter=0;
   double grade;
   double total=0;
   double average=0;
   puts("Enter one grade at a time, and enter -1 to finish.");
   do
   {
      printf("Enter grade (-1 to finish): ");
      scanf("%lf", &grade);
      if (grade != -1)
      {
         total += grade;
         counter++;
      }
   } while (grade != -1);  
   // we need to be sure that the user has entered at least one grade otherwise we will return 0
   if (counter > 0) {
      average = total / counter;
      return average;
   }
   else{
      return 0.0;
   }
}