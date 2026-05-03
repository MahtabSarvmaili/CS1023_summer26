#include <stdio.h>

void testStatic(void);

int main(void)
{
    testStatic();
    testStatic();
    return 0;
}

void testStatic(void)
{
    static int x = 0;
    printf("x = %d\n", x);
    x++;
    printf("x = %d\n", x);
}