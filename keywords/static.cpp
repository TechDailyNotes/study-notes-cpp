#include <iostream>

using namespace std;

struct Entity {
    int x, y;

    void print() {
        cout << "x = " << x << ", y = " << y << endl;
    }
};

int main() {
    Entity e;
    e.x = 2;
    e.y = 3;

    Entity e1 = {5, 8};

    e.print();
    e1.print();
}