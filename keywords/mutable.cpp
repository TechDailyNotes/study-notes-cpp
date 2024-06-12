#include <iostream>
#include <string>

using namespace std;

class Entity
{
private:
    string mName;
    mutable int mDebugCount = 0;

public:
    const string &getName() const
    {
        mDebugCount++;
        return mName;
    }
};

int main()
{
    const Entity e;
    e.getName();

    int x = 8;
    auto f = [=]() mutable
    {
        cout << x << endl;
    };

    f();
}