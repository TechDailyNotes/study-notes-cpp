#include <iostream>

using namespace std;

#pragma pack(push, 1)

struct UnalignedStruct {
    char a;
    short b;
    int c;
};

#pragma pack(pop)

struct AlignedStruct {
    char a;
    short b;
    int c;
};

struct AlignedStruct2 {
    UnalignedStruct s;
    double a;
    int d;
    char b[5];
};

int main() {
    cout << "Size of `UnalignedStruct` is " << sizeof(UnalignedStruct) << endl;
    cout << "Size of `AlignedStruct` is " << sizeof(AlignedStruct) << endl;
    cout << "Size of `AlignedStruct2` is " << sizeof(AlignedStruct2) << endl;
}