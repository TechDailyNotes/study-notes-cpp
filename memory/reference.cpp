#include <iostream>
#include <stdio.h>

int main() {
    int a = 1;
    int b = 2;

    int &ra = a, &rb = b;

    std::cout << "ra is " << ra << std::endl;
    std::cout << "rb is " << rb << std::endl;

    ra = rb;

    printf("ra is %d\n", ra);
    printf("rb is %d\n", rb);

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;

    return 0;
}