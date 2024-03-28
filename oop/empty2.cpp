#include <iostream>

using namespace std;

class Empty {};

class Int : public Empty {
public:
    int a;
};

int main() {
    Int *p = new Int;

    void *pa = p;
    void *pb = &p->a;

    cout << (pa == pb) << endl;

    return 0;
}