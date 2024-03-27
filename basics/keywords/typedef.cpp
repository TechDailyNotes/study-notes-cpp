#include <vector>

using namespace std;

template <typename T>
struct MyStruct1 {
    typedef vector<T> Type;
};

template <typename T>
struct MyStruct2 {
    using Type = vector<int>;
};

int main() {
    MyStruct1<int>* s1 = new MyStruct1<int>();
    MyStruct2<int>* s2 = new MyStruct2<int>();

    return 0;
}