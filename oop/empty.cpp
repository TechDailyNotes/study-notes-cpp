#include <iostream>

using namespace std;

class Empty {};

struct Int: Empty {
    int a;
};

int main() {
    Empty *p1 = new Empty, *p2 = new Empty;

    if (p1 == p2) {
        cout << "Same address." << endl;
    } else {
        cout << "Different address." << endl;
    }

    cout << "Size of Empty is " << sizeof(Empty) << endl;
    cout << "Size of p1 is " << sizeof(*p1) << endl;

    delete p1;
    delete p2;

    Empty a, b;

    if (&a == &b) {
        cout << "Same address." << endl;
    } else {
        cout << "Different address." << endl;
    }

    cout << "Size of a is " << sizeof(a) << endl;

    Int *p = new Int;
    void *pa = p;
    void *pb = &p->a;

    if (pa == pb) {
        cout << "pa == pb" << endl;
    }

    return 0;
}