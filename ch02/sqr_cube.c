#include <stdio.h>
#include <stdlib.h>

int main(void){
    int i;
    for (i=0; i<11; i++)
    {
        printf("%d \t %d \t %d\n", i, i*i, i*i*i);
    }
    return 0;
}