#include <stdio.h>

struct Ints {
    // int a;
    // int b;
    int *c;
};

int main() {
    // Ints i;
    // i.a = 1;
    // i.b = 2;

    // printf("Ints::a = %d\n", i.a);
    // printf("Ints::b = %d\n", i.b);

    // ((Ints*)&i.b)->a = 3;

    // printf("Ints::a = %d\n", i.a);
    // printf("Ints::b = %d\n", i.b);
    printf("Size of Ints is %lu\n", sizeof(Ints));
}