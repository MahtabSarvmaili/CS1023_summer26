#include <stdio.h>

int global_var = 10;
static int file_private = 20;

void demo() {
    static int persistent = 0;
    register int i;

    persistent++;

    for (i = 0; i < 2; i++) {
        printf("i=%d persistent=%d global=%d file_private=%d\n",
               i, persistent, global_var, file_private);
    }

label:
    if (persistent < 3)
        goto label;
}

int main() {
    demo();
    demo();
    return 0;
    
}