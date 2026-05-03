#include <stdio.h>

int main(void)
{
    int i, j;
    int star_count = 5;
    for (i = 0; i <= star_count; i++) 
    {

            if (i ==0 || i == star_count){
               for (j=0; j<= star_count; j++)
                {
                    printf("*");
                }
            }
            else
            {
                printf("*");
                for (j=0; j<= star_count-2; j++)
                {
                    printf(" ");
                }
                printf("*");
            }         
        printf("\n");
    }   
}