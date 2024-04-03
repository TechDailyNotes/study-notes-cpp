#include <iostream>
#include <type_traits>

// void foo(int a) {}
// void foo(int *a) {}

template <typename T>
void foo(T t) {
    if (std::is_same<T, std::nullptr_t>::value) {
        std::cout << "nullptr" << std::endl;
    } else {
        std::cout << "non-nullptr" << std::endl;
    }
}

int main() {
    foo(NULL);
    foo(nullptr);

    return 0;
}