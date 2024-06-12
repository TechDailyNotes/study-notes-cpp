#include <iostream>

using namespace std;

int main() {
    int n = 69;
    cout << "Number is " << n << endl;
    char *c = reinterpret_cast<char*>(&n);
    cout << "Character is " << *c << endl;

    return 0;
}