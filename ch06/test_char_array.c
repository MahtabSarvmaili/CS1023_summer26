#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int string1[4]; // {'f', 'o', 'o', '\0', 'h', 'i', '\0'}; // String literal stored in an array
    
    printf("string1: %p\n", (void *)string1); // Output: "foo"
}