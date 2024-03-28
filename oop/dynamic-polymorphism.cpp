#include <iostream>

using namespace std;

class Shape {
public:
    virtual void printArea() = 0;
};

class Rectangle : public Shape {
public:
    Rectangle(int height, int width)
        : height(height), width(width) {}

    void printArea() override {
        cout << "Area of the rectangle is " << height * width << endl;
    }

private:
    int height, width;
};

class Triangle : public Shape {
public:
    Triangle(int height, int width)
        : height(height), width(width) {}

    void printArea() override {
        cout << "Area of the triangle is " << height * width / 2 << endl;
    }

private:
    int height, width;
};

int main() {
    Shape *shape;

    Rectangle rec(2, 3);
    shape = &rec;
    shape->printArea();

    Triangle tri(2, 3);
    shape = &tri;
    shape->printArea();

    return 0;
}