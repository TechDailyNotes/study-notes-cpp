#include <iostream>

template <typename T>
class MySharedPtr {
public:
    MySharedPtr(T* ptr)
        : ptr_(ptr), cnt_(ptr ? new size_t(1) : nullptr) {
            std::cout << "MySharedPtr::MySharedPtr(T* ptr)" << std::endl;
        }

    MySharedPtr(const MySharedPtr& other) {
        std::cout << "MySharedPtr::MySharedPtr(const MySharedPtr& other)" << std::endl;

        ptr_ = other.ptr_;
        cnt_ = other.cnt_;

        if (cnt_) {
            (*cnt_)++;
        }
    }

    MySharedPtr& operator=(const MySharedPtr& other) {
        std::cout << "MySharedPtr::MySharedPtr& operator=(const MySharedPtr& other)" << std::endl;

        if (this != &other) {
            release();
        }

        return *this;
    }

    ~MySharedPtr() {
        std::cout << "MySharedPtr::~MySharedPtr()" << std::endl;

        release();
    }

    size_t use_count() { return cnt_ ? *cnt_ : 0; }
    T& operator*() { return *ptr_; }
    T* operator->() { return ptr_; }
    T* get() { return ptr_; }

private:
    T *ptr_;
    size_t *cnt_;

    void release() {
        if (cnt_ && --(*cnt_) == 0) {
            delete ptr_;
            delete cnt_;
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