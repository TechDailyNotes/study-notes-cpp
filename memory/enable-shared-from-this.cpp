// #include <iostream>
// #include <memory>

// class Base;

// void callAPI(const std::shared_ptr<Base>& pb) {}

// class Base : std::enable_shared_from_this<Base> {
// public:
//     static std::shared_ptr<Base> getInstance() {
//         return std::shared_ptr<Base>(new Base);
//     }

//     void call() {
//         callAPI(shared_from_this());
//     }

//     ~Base() {
//         std::cout << "Base::~Base()" << std::endl;
//     }

// private:
//     Base() {}
// };

// int main() {
//     auto pb = Base::getInstance();
//     pb->call();
//     std::cout << "After `pb->call()`" << std::endl;
//     return 0;
// }

#include <memory>
#include <iostream>

struct SomeData;
void SomeAPI(const std::shared_ptr<SomeData> &d) {}

struct SomeData : std::enable_shared_from_this<SomeData>
{
    static std::shared_ptr<SomeData> Create()
    {
        return std::shared_ptr<SomeData>(new SomeData);
    }
    void NeedCallSomeAPI()
    {
        SomeAPI(shared_from_this());
    }

private:
    SomeData() {}
};

int main()
{
    auto d = SomeData::Create();
    d->NeedCallSomeAPI();
    std::cout << "after SomeData::NeedCallSomeAPI()" << std::endl;
}
