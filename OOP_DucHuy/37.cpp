#include <iostream>
using namespace std;

class Base
{
    int prop;

public:
    Base();
    Base(int);
    ~Base();
    int getProp();
};
Base::Base()
    : prop(10)
{
}
Base::Base(int prop)
    : prop(prop)
{
}
Base::~Base()
{
}
int Base::getProp()
{
    return this->prop;
}
class Derived : public Base
{
    int prop;

public:
    Derived(int);
    ~Derived();
};
Derived::Derived(int prop)
    : prop(prop)
{
}
Derived::~Derived()
{
}
int main()
{
    Derived obj(100);
    cout << obj.getProp() << obj.getProp();
    return 0;
}

// Kết quả: 1010
// Giải thích: Lớp cơ sở Base chứa một thuộc tính prop và một phương thức getProp() để truy cập vào thuộc tính này. Lớp dẫn xuất Derived cũng chứa một thuộc tính prop. Khi tạo một đối tượng của lớp dẫn xuất Derived với giá trị prop là 100, phương thức getProp() của lớp cơ sở Base trả về giá trị prop của lớp cơ sở, tức là 10. Do đó, kết quả là 1010.