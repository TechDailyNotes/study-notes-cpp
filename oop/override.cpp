#include <iostream>

using namespace std;

class Base {
public:
    // virtual void display() {
    //     cout << "Display in the base class." << endl;
    // };
    // virtual void display() = 0;
    void display(int a) {
        cout << "Number is " << a << endl;
    }
};

class Derived : public Base {
public:
    // void display() override {
    //     cout << "Display in the derived class." << endl;
    // };
    int display(int a, int b) {
        cout << "Sum is " << a + b << endl;
        return a + b;
    }
};

int main() {
    Derived *derived = new Derived();
    derived->display(1, 2);

    return 0;
}