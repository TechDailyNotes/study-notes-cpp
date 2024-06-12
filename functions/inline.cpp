#include <iostream>

using namespace std;

inline int square(int a) {
    return a * a;
}

int main() {
    double a = 6.2;
    double sq = square(a);
    cout << sq << endl;
}