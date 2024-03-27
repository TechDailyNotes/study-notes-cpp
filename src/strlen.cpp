#include <iostream>

using namespace std;

// void printSize(char str[]);
// template <typename T, size_t N>
// void getSize(const T (&arr) [N]) {
//     cout << sizeof(arr) << endl;
//     cout << strlen(arr) << endl;
// }

template <size_t N>
void getSize(const char (&arr) [N]) {
    cout << sizeof(arr) << endl;
}

void getPointerSize(const char arr[]) {
    cout << sizeof(arr) << endl;
}

int main() {
    char str[] = "Hello World!";
    // printSize(str);
    getPointerSize(str);
}

// void printSize(char str[]) {
//     cout << strlen(str) << endl;
//     cout << sizeof(str) << endl;
// }
