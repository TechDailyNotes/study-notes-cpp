#include <iostream>

using namespace std;

class Base1 {
public:
    Base1() {
        cout << "Base1 Constructor." << endl;
    }

    ~Base1() {
        cout << "Base1 Destructor." << endl;
    }
};

class Base2 {
public:
    Base2() {
        cout << "Base2 Constructor." << endl;
    }

    ~Base2() {
        cout << "Base2 Destructor." << endl;
    }
};

class Base3 {
public:
    Base3() {
        cout << "Base3 Constructor." << endl;
    }

    ~Base3() {
        cout << "Base3 Destructor." << endl;
    }
};

class Property1 {
public:
    Property1() {
        cout << "Property1 Constructor." << endl;
    }

    ~Property1() {
        cout << "Property1 Destructor." << endl;
    }
};

class Property2 {
public:
    Property2()
    {
        cout << "Property2 Constructor." << endl;
    }

    ~Property2()
    {
        cout << "Property2 Destructor." << endl;
    }
};

class Class : public Base1, public virtual Base3, public virtual Base2 {
public:
    Class() {
        cout << "Class Constructor." << endl;
    }

    ~Class() {
        cout << "Class Destructor." << endl;
    }

private:
    Property2 p2;
    Property1 p1;
};

int main() {
    Class c;
    return 0;
}