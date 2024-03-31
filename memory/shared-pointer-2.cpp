#include <iostream>

class MyClass {
public:
    MyClass() {
        std::cout << "MyClass()" << std::endl;
    }

    ~MyClass() {
        std::cout << "~MyClass()" << std::endl;
    }

    void doSomething() {
        std::cout << "doSomething()" << std::endl;
    }
};

int main() {
    std::shared_ptr<MyClass> p1 = std::make_shared<MyClass>();
    {
        std::shared_ptr<MyClass> p2 = p1;
        std::cout << p1.use_count() << std::endl;
    }
    std::cout << p1.use_count() << std::endl;

    return 0;
}