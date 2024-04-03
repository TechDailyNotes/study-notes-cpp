#include <cstdlib>

void foo(int x) {}
void foo(int *x) {}

int main() {
    foo(nullptr);
    return 0;
}
