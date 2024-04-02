#include <iostream>

template <typename T>
class MySharedPtr {
public:
    explicit MySharedPtr(T *ptr = nullptr)
        : _ptr(ptr), _count(ptr ? new size_t(1) : nullptr) {}

    MySharedPtr(const MySharedPtr& other)
        : _ptr(other._ptr), _count(other._count)
    {
        if (_count)
        {
            (*_count)++;
        }
    }

    MySharedPtr& operator=(const MySharedPtr& other) {
        if (this != &other) 
        {
            release();

            _ptr = other._ptr;
            _count = other._count;

            if (_count) {
                (*_count)++;
            }
        }

        return *this;
    }

    ~MySharedPtr() {
        release();
    }

    T& operator*() const { return *_ptr; }
    T* operator->() const { return _ptr; }
    T* get() const { return _ptr; }
    size_t use_count() const { return _count ? *_count : 0; }

private:
    T *_ptr;
    size_t *_count;

    void release() {
        if (_count && --(*_count) == 0) {
            delete _ptr;
            delete _count;
        }
    }
};

class MyClass {
public:
    MyClass() {
        std::cout << "MyClass::MyClass()" << std::endl;
    }

    ~MyClass() {
        std::cout << "MyClass::~MyClass()" << std::endl;
    }
};

int main() {
    MySharedPtr<MyClass> p1(new MyClass);
    std::cout << p1.use_count() << std::endl;
    {
        MySharedPtr<MyClass> p2 = p1;
        std::cout << p1.use_count() << std::endl;
    }
    std::cout << p1.use_count() << std::endl;
    return 0;
}