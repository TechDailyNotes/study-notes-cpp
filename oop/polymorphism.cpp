#include <iostream>

using namespace std;

class Base {
public:
    virtual void DO() {
        cout << "Base" << endl;
    }
};

class Derived : public Base {
public:
    void DO() override
    {
        cout << "Derived" << endl;
    }
};

int main() {
    Base* base = new Derived();
    base->DO();
    return 0;
}