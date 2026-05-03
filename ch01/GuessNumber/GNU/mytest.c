#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int getRandom(int); // function prototype
int isCorrect(int, int); // function prototype

int main(void)
{
    char name[100];
    int age;
    int phone_number;

    printf("What is your name? ");
    scanf("%s", name);
    printf("What is your age? ");
    scanf("%d", &age);
    printf("What is your phone number? ");
    scanf("%d", &phone_number);
    printf("Hello, %s! You are %d years old and your phone number is %d.\n", name, age, phone_number);
    return 0;

}