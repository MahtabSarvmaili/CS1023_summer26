#include <stdio.h>


void printDiamond(void);

int main(void)
{
    int rows;
    int a;
    puts("Enter the number of rows for the diamond (1-5):\n");
    scanf("%d", &rows);
    a = rows/2;
    printf(rows/2 ? "invalid input": "processing that");
    printf("%d\n", a);

}

void printDiamond(void)
{
    int i=0, j=0, k =0;
    printf("%d %d %d\n", i, j, k);
    for (i = 1; i <= 5; i++) {
        for (j = 1; j <= 5 - i; j++) {
            printf(" ");
        }
        for (k = 1; k <= 2 * i - 1; k++) {
            printf("*");
        }
        printf("\n");
    }
    for (i = 4; i >= 1; i--) {
        for (j = 1; j <= 5 - i; j++) {
            printf(" ");
        }
        for (k = 1; k <= 2 * i - 1; k++) {
            printf("*");
        }
        printf("\n");
    }
}