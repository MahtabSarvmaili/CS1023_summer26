#include <stdio.h>

int main(void)
{
    char userInput[100];

    printf("Enter some text: ");
    fgets(userInput, sizeof(userInput), stdin);

    // Vulnerable usage
    printf(userInput);

    return 0;
}

// try with Hello
// Output: Hello

// try with Hello %x %x %x
// Output: Hello 0x7ffde5c8 0x7ffde

/*

The %x format specifiers tell printf to read integers from the stack and print them in hexadecimal. 

Since no extra arguments were actually provided to printf, 
it starts reading whatever happens to exist in memory after the function arguments. 
This is the classic format string vulnerability.

*/