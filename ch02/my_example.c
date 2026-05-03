#include <stdio.h>
#include <stdlib.h>

int main(void){
    int num1, num2;
    printf("Enter the first integer:\n");
    scanf("%d", &num1);
    printf("Enter the second integer:\n");
    scanf("%d", &num2);

    if (num1 == num2)
    {
        printf("Integer1 %d is equal to Integer2 %d\n", num1, num2);
    }else if (num1 >= num2)
    {
        printf("Integer1 %d is greater than or equal to Integer2 %d\n", num1, num2);
    }
    else
    {
        printf("Integer1 %d is less than or equal to Integer2 %d\n", num1, num2);
    }

    // testing the while 
    int integer1 = 0;
    while (integer1< num1)
    {
        printf("Enter your selected integer:\n");
        scanf("%d", &integer1);
        printf("You entered %d\n", integer1);
    }

    // arithmatic operations

    int int1, int2;
    float result;
    printf("Enter the first integer:\n");
    scanf("%d", &int1);
    printf("Enter the second integer:\n");
    scanf("%d", &int2); 

    // addition
    result = int1 + int2;
    printf("The result of addition is: %.8f\n", result);

    // division
    result = (float)int1/int2;
    printf("The result of division is: %.8f\n", result);
    return 0;
}