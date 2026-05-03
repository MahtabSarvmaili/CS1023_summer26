#include <stdio.h>


int main(void)
{
    int i =0, j=0;

    printf("i before ++ operator: %d\n", i);
    printf("i if we use i++: %d\n", i++); // post increment operator: returns the value before incrementing
    printf("i if we use ++i: %d\n", ++i); // pre increment operator: increments the value first and then returns it

}