#include <stdio.h>
#include <iostream>

int main() {
    int a[10] = { 1 };

    printf("a[0] = %d\n", a[0]);
    printf("*a = %d\n", *a);

    std::cout << "a[1] = " << a[1] << std::endl;
    std::cout << "*(a+1) = " << *(a+1) << std::endl;

    printf("0[a] = %d\n", 0[a]);
    printf("1[a] = %d\n", 1[a]);

    int *b = a;
    std::cout << "Size of a is " << sizeof(a) << std::endl;
    printf("Size of b is %lu\n", sizeof(b));
}