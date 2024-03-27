#include <iostream>

class MyClass {
public:
    int a;

    explicit MyClass(int a): a(a) {}
};

int main() {
    MyClass c = MyClass(3);
    std::cout << c.a << std::endl;
}