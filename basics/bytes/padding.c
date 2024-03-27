#include <stdio.h>

typedef struct EmptyStruct {} EmptyStruct_;

int main() {
    printf("%lu", sizeof(EmptyStruct_));
}