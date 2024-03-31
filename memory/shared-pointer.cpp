#include <memory>
#include <iostream>

int main() {
    std::shared_ptr<int> p1(new int(10));
    std::shared_ptr<int> p2 = p1;

    std::cout << *p1 << " " << *p2 << std::endl;

    return 0;
}