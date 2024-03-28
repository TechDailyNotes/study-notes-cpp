#include <iostream>

using namespace std;

class MyClass {
public:
    void non_const_func() {};
};

int main() {
    const MyClass myclass;
    MyClass *_myclass = const_cast<MyClass*>(&myclass);
    _myclass->non_const_func();

    const int a = 1;
    int *a_ptr = const_cast<int*>(&a);
    *a_ptr = 2;
    cout << *a_ptr << endl;
    return 0;
}
