// #include <memory>
// #include <iostream>

// int main() {
//     std::shared_ptr<int> p(new int(1));
//     std::weak_ptr<int> wp = p;

//     if (!wp.expired()) {
//         auto sp = wp.lock();
//         if (sp) {
//             std::cout << *sp << std::endl;
//         }
//     }
// }

#include <memory>
#include <iostream>

int main() {
    std::shared_ptr<int> p = std::make_shared<int>(1);
    std::weak_ptr<int> wp = p;

    if (!wp.expired()) {
        std::shared_ptr<int> sp = wp.lock();

        if (sp) {
            std::cout << *sp << std::endl;
        }
    }

    return 0;
}