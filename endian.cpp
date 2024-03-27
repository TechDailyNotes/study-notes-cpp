#include <iostream>

using namespace std;

int main() {
    int a = 1;
    char *aPtr = reinterpret_cast<char*>(&a);
    if (*aPtr == 1) {
        cout << "Little Endian" << endl;
    } else {
        cout << "Big Endian" << endl;
    }
    return 0;
}
