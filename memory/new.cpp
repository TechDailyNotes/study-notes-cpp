#include <cstdlib>
#include <iostream>
#include <stdio.h>

int main() {
    int *a = new int[10];
    std::cout << a[9] << std::endl;
    delete[] a;

    int *b = (int *) malloc(sizeof(int) * 10);
    printf("%d\n", b[9]);
    free(b);
}