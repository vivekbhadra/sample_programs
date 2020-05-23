#include <iostream>

using namespace std;

class MyClass {
};

void foo(MyClass *p)
{
}
int main()
{
    const MyClass *pMyClass = new MyClass;
    foo(const_cast<MyClass *>(pMyClass));
    return 0;
}
