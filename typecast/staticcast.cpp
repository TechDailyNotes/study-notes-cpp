#include <iostream>

using namespace std;

class Base {};
class Derived: public Base {};

int main() {
    // cout << sizeof(Base) << endl;
    // cout << sizeof(Derived) << endl;

    int a = 5;
    double b = static_cast<double>(a);

    Base *base_ptr = new Derived();
    Derived *derived_ptr = static_cast<Derived*>(base_ptr);

    Derived derived;
    Base& base_ref = derived;
    Derived& derived_ref = static_cast<Derived&>(base_ref);

    return 0;
}