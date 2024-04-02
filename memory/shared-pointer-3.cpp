#include <iostream>
#include <memory>

class B;

class A {
public:
    std::shared_ptr<B> pb;

    ~A() {
        std::cout << "A::~A()" << std::endl;
    }
};

class B {
public:
    std::weak_ptr<A> pa;

    ~B() {
        std::cout << "B::~B()" << std::endl;
    }
};

int main() {
    std::shared_ptr<A> pa = std::make_shared<A>();
    std::shared_ptr<B> pb = std::make_shared<B>();

    pa->pb = pb;
    pb->pa = pa;

    return 0;
}
