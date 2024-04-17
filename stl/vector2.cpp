#include <iostream>
#include <utility>

template <typename T>
class Vector {
private:
    T* _items;
    size_t _capacity;
    size_t _size;

public:
    Vector()
        : _items(new T[1]), _capacity(1), _size(0) {
            std::cout << "Vector()" << std::endl;
        }

    ~Vector() {
        std::cout << "~Vector()" << std::endl;
        delete[] _items;
    }

    Vector(const Vector& other)
        : _items(new T[other._capacity]), _capacity(other._capacity), _size(other._size) {
            std::cout << "Vector(const Vector& other)" << std::endl;
            memcpy(_items, other._items, sizeof(T) * _size);
        }

    Vector(Vector&& other)
        : _items(other._items), _capacity(other._capacity), _size(other._size) {
            std::cout << "Vector(Vector&& other)" << std::endl;
            other._items = nullptr;
            other._capacity = 0;
            other._size = 0;
        }

    Vector& operator=(const Vector& other) {
        std::cout << "Vector& operator=(const Vector& other)" << std::endl;
        if (this != &other) {
            _capacity = other._capacity;
            _size = other._size;
            delete[] _items;
            _items = new T[_capacity];
            memcpy(_items, other._items, sizeof(T) * _size);
        }
        return *this;
    }

    Vector& operator=(Vector&& other) {
        if (this != &other) {
            delete[] _items;
            _items = other._items;
            _capacity = other._capacity;
            _size = other._size;
            other._items = nullptr;
            other._capacity = 0;
            other._size = 0;
        }
        return *this;
    }

    void reserve(size_t number) {
        if (number > _capacity) {
            T* newItems = new T[number];
            memcpy(newItems, _items, sizeof(T) * _size);
            delete[] _items;
            _items = newItems;
            _capacity = number;
        }
    }

    void push(T item) {
        if (_size == _capacity) {
            std::cout << "Expand capacity from " << _capacity << " to " << 2 * _capacity << std::endl;
            reserve(2 * _capacity);
        }
        _items[_size++] = item;
    }

    void pop() {
        if (_size > 0) {
            _size--;
        }
    }

    size_t size() {
        return _size;
    }

    size_t capacity() {
        return _capacity;
    }

    T& front() {
        if (_size > 0) {
            return _items[0];
        }
    }

    T& back() {
        if (_size > 0) {
            return _items[_size-1];
        }
    }

    T& operator[](size_t index) {
        if (index < _size) {
            return _items[index];
        }
    }
};

std::ostream& operator<<(std::ostream& os, Vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        os << v[i] << " ";
    }
    return os;
}

int main() {
    std::cout << "Test 1" << std::endl;
    Vector<int> v1;
    v1.push(1);
    v1.push(2);
    v1.push(3);
    v1.push(4);
    v1.push(5);
    std::cout << v1 << std::endl;
    v1.pop();
    v1.pop();
    std::cout << v1 << std::endl;
    v1.reserve(8);
    std::cout << v1.capacity() << std::endl;
    std::cout << v1.size() << std::endl;
    v1.push(4);
    v1.push(5);
    v1.push(6);
    v1.push(7);
    v1.push(8);
    v1.push(9);
    std::cout << v1 << std::endl;
    v1[0] = 100;
    std::cout << v1 << std::endl;
    std::cout << std::endl;

    std::cout << "Test 2" << std::endl;
    Vector<int> v2 = v1;
    std::cout << v1 << std::endl;
    std::cout << v2 << std::endl;
    v2[0] = 200;
    std::cout << v1 << std::endl;
    std::cout << v2 << std::endl;
    std::cout << std::endl;

    std::cout << "Test 3" << std::endl;
    Vector<int> v3;
    v3 = v1;
    std::cout << v1 << std::endl;
    std::cout << v3 << std::endl;
    v3[0] = 300;
    std::cout << v1 << std::endl;
    std::cout << v3 << std::endl;
    std::cout << std::endl;

    std::cout << "Test 4" << std::endl;
    Vector<int> v4 = std::move(v2);
    std::cout << v2 << std::endl;
    std::cout << v4 << std::endl;
    v4[0] = 400;
    std::cout << v2 << std::endl;
    std::cout << v4 << std::endl;
    std::cout << std::endl;

    std::cout << "Test 5" << std::endl;
    Vector<int> v5;
    v5 = std::move(v3);
    std::cout << v3 << std::endl;
    std::cout << v5 << std::endl;
    v5[0] = 500;
    std::cout << v3 << std::endl;
    std::cout << v5 << std::endl;
    std::cout << std::endl;

    return 0;
}