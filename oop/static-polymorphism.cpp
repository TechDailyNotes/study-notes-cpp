#include <iostream>

using namespace std;

template <class T>
T getMax(T n1, T n2) {
    return n1 > n2 ? n1 : n2;
}

int main() {
    cout << getMax<int>(1, 2) << endl;
    cout << getMax<unsigned long>(1LU, 2LU) << endl;
    return 0;
}