// #include <type_traits>
// #include <iostream>

// template <typename T>
// typename std::enable_if<std::is_integral<T>::value, T>::type
// foo(T t) {
//     std::cout << "int" << std::endl;
//     return t;
// }

// template <typename T>
// typename std::enable_if<std::is_floating_point<T>::value, T>::type
// foo(T t) {
//     std::cout << "float" << std::endl;
//     return t;
// }

// int main() {
//     foo(1);
//     foo(.1);
// }

#include <type_traits>
#include <iostream>

template <typename T>
typename std::enable_if<std::is_integral<T>::value, T>::type
foo(T t) {
    std::cout << "int" << std::endl;
    return t;
}

template <typename T>
typename std::enable_if<std::is_floating_point<T>::value, T>::type
foo(T t) {
    std::cout << "float" << std::endl;
    return t;
}

int main() {
    foo(1);
    foo(1.);

    return 0;
}