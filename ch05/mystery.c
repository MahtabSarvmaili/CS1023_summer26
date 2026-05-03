#include <stdio.h>

int mystery(unsigned int x, unsigned int y);

int main(void)
{
    unsigned int a, b;
    printf("Enter two positive integers:\n");
    scanf("%u %u", &a, &b);
    unsigned int result = mystery(a, b);
    printf("The result of mystery(%u, %u) is: %u\n", a, b, result);
}

int mystery(unsigned int x, unsigned int y)
{
    if (1==y){
        return x;
    
    } else
    {
        return x+mystery(x, y-1);
    }
}