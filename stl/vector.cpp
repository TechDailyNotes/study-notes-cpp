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
        :_items(new T[1]), _capacity(1), _size(0) {
            std::cout << "Vector()" << std::endl;
        }

    ~Vector() {
        delete[] _items;
        std::cout << "~Vector()" << std::endl;
    }

    // Copy constructor
    Vector(const Vector& other)
        : _items(new T[other._capacity]), _capacity(other._capacity), _size(other._size) {
            // std::copy(other._items, other._items + other._size, _items);
            memcpy(_items, other._items, sizeof(T) * _size);
            std::cout << "Vector(const Vector& other)" << std::endl;
        }

    // Copy assignment operator
    Vector& operator=(const Vector &other) {
        std::cout << "Vector& operator=(const Vector& other)" << std::endl;
        if (this != &other) {
            delete[] _items;
            _capacity = other._capacity;
            _size = other._size;
            _items = new T[other._capacity];
            // std::copy(other._items, other._items + other._size, _items);
            memcpy(_items, other._items, sizeof(T) * _size);
        }
        return *this;
    }

    // Move constructor
    Vector(Vector&& other)
        :_items(other._items), _capacity(other._capacity), _size(other._size) {
            std::cout << "Vector(Vector&& other)" << std::endl;
            other._items = nullptr;
            other._capacity = 0;
            other._size = 0;
        }

    // Move assignment operator
    Vector& operator=(Vector&& other) {
        std::cout << "Vector& operator=(Vector&& other)" << std::endl;
        if (this != &other) {
            delete[] _items;
            _items = other._items;
            other._items = nullptr;
            _capacity = other._capacity;
            other._capacity = 0;
            _size = other._size;
            other._size = 0;
        }
        return *this;
    }

    void push(const T& item) {
        if (_size >= _capacity) {
            std::cout << "Extending capacity from " << _capacity << " to " << 2 * _capacity << std::endl;
            T* _newItems = new T[2*_capacity];
            // std::copy(_items, _items + _size, _newItems);
            memcpy(_newItems, _items, sizeof(T) * _size);
            delete[] _items;
            _items = _newItems;
            _capacity *= 2;
        }

        _items[_size++] = item;
    }

    void pop() {
        if (_size > 0) {
            _size--;
        }
    }

    void reserve(const size_t number) {
        if (number > _capacity) {
            T* _newItems = new T[number];
            // std::copy(_items, _items + _size, _newItems);
            memcpy(_newItems, _items, sizeof(T) * _size);
            delete[] _items;
            _items = _newItems;
            _capacity = number;
        }
    }

    size_t size() {
        return _size;
    }

    T& front() {
        return _items[0];
    }

    T& back() {
        return _items[_size-1];
    }

    T& operator[](const size_t index) {
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
    std::cout << std::endl;

    v1.pop();
    v1.pop();
    std::cout << v1 << std::endl;

    v1.reserve(8);
    v1.push(4);
    v1.push(5);
    v1.push(6);
    v1.push(7);
    v1.push(8);
    v1.push(9);
    std::cout << v1 << std::endl;

    std::cout << v1.front() << std::endl;
    std::cout << v1.back() << std::endl;

    v1[0] = 100;
    std::cout << v1 << std::endl;

    std::cout << "Test 2" << std::endl;
    Vector<int> v2 = v1;
    std::cout << v1 << std::endl;
    std::cout << v2 << std::endl;
    std::cout << std::endl;

    std::cout << "Test 3" << std::endl;
    Vector<int> v3;
    v3 = v1;
    std::cout << v1 << std::endl;
    std::cout << v3 << std::endl;
    std::cout << std::endl;

    std::cout << "Test 4" << std::endl;
    Vector<int> v4(std::move(v1));
    std::cout << v1 << std::endl;
    std::cout << v4 << std::endl;
    std::cout << std::endl;

    std::cout << "Test 5" << std::endl;
    Vector<int> v5;
    v5 = std::move(v4);
    std::cout << v4 << std::endl;
    std::cout << v5 << std::endl;
    std::cout << std::endl;

    std::cout << v2 << std::endl;
    std::cout << v3 << std::endl;

    return 0;
}