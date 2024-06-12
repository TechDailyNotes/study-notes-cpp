// #include <iostream>
// #include <string>

// extern "C" {
//     void printMessage(const char *message);
// }

// int main() {
//     std::string str = "hello";
//     // const char *message = str.c_str();
//     // printMessage(str.c_str());
//     std::cout << "hello\0" << std::endl;
//     return 0;
// }

// #define i int

extern "C" {
    void printMessage(const char* message);
}

int main() {
    const char* message = "Hello";
    printMessage(message);
    // i a = 1;
    // std::cout << a << std::endl;

    return 0;
}