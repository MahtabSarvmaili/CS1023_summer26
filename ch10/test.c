#include <stdio.h>

union Data {
    int i;
    float f;
};

int main(void) {
    union Data d;

    d.i = 100;
    printf("i = %d\n", d.i);

    d.f = 3.14f;
    printf("f = %.2f\n", d.f);

    printf("i = %d\n", d.i);
}