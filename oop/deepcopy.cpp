#include <iostream>
#include <cstring>

using namespace std;

class MyString {
public:
    MyString(const char* str) {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    MyString(const MyString& other) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
    }

    MyString& operator=(const MyString& other) {
        if (this == &other) {
            return *this;
        }

        delete[] data;
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
        return *this;
    }

    void setData(const char* str) {
        if (data != NULL) {
            delete[] data;
        }

        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    void print() {
        cout << data << endl;
    }

    ~MyString() {
        delete[] data;
    }

private:
    char *data;
};

int main() {
    MyString s1("Hello World!");
    MyString s2 = s1;

    s1.print();
    s2.print();

    s2.setData("Hello!");
    s1.print();
    s2.print();

    return 0;
}