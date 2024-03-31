#include <iostream>

class MyClass {
public:
    MyClass() {
        std::cout << "MyClass()" << std::endl;
    };

    MyClass(MyClass& other) {
        std::cout << "MyClass(MyClass& other)" << std::endl;
    }

    MyClass& operator=(const MyClass& other) {
        std::cout << "operator=(MyClass& other)" << std::endl;

        return *this;
    }
};

int main() {
    MyClass c1;
    MyClass c2 = c1;
    MyClass c3(c1);
    c2 = c3;

    return 0;
}