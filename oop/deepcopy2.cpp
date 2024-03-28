#include <cstring>
#include <iostream>

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

    ~MyString() {
        delete[] data;
    }

    friend ostream& operator<<(ostream& os, const MyString& str);

private:
    char *data;
};

ostream& operator<<(ostream& os, const MyString& str) {
    os << str.data;
    return os;
}

int main() {
    MyString s1("Hello World!");
    MyString s2(s1);
    cout << "String 1 is " << s1 << endl;
    cout << "String 2 is " << s2 << endl;

    s2.setData("Hello~");
    cout << "String 1 is " << s1 << endl;
    cout << "String 2 is " << s2 << endl;
    return 0;
}