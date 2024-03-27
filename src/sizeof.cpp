#include <iostream>

using namespace std;

struct MyStruct
{
    int a;
    double b;
    char c;
};

struct AlignedStruct
{
    char a;  // 本来1字节，padding 3 字节
    int b;   //  4 字节
    short c; // 本来 short 2字节，但是整体需要按照 4 字节对齐(成员对齐边界最大的是int 4) ，
    // 所以需要padding 2，总共: 4 + 4 + 4
};

// void getSize(int arr[]) {
//     cout << sizeof(arr) << endl;
// }

struct EmptyStruct {};

int main()
{
    // char arr[] = "Hello World!";
    // int *arr = (int*) malloc(100);
    int arr[10];
    cout << sizeof(arr) << endl;
    // getSize(arr);
}
