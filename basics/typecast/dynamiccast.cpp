#include <iostream>

using namespace std;

class Animal {
public:
    virtual ~Animal() {};
};

class Dog : public Animal {
public:
    void bark() {
        cout << "Dog barks." << endl;
    }
};

class Cat : public Animal {
public:
    void meow() {
        cout << "Cat meows." << endl;
    }
};

int main() {
    Animal *animal = new Animal();

    Dog *dog = dynamic_cast<Dog*>(animal);
    if (dog == nullptr) {
        dog->bark();
    }

    Cat *cat = dynamic_cast<Cat*>(animal);
    if (cat == nullptr) {
        cat->meow();
    }

    return 0;
}
