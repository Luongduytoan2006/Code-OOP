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
    int GetProp();
};
Derived::Derived(int prop)
    : prop(prop)
{
}
Derived::~Derived()
{
}
int Derived::GetProp()
{
    return this->prop;
}

int main()
{
    Derived obj(100);
    cout << obj.getProp() << " " << obj.GetProp();
    return 0;
}

// Kết quả: 10 100
// Giải thích: Lớp cơ sở Base chứa một thuộc tính prop và một phương thức getProp() để truy cập vào thuộc tính này. Lớp dẫn xuất Derived cũng chứa một thuộc tính prop và một phương thức GetProp() để truy cập vào thuộc tính này. Khi tạo một đối tượng của lớp dẫn xuất Derived với giá trị prop là 100, phương thức getProp() của lớp cơ sở Base trả về giá trị prop của lớp cơ sở, tức là 10. Phương thức GetProp() của lớp dẫn xuất Derived trả về giá trị prop của lớp dẫn xuất, tức là 100. Do đó, kết quả là 10 100.

// file đang tạm dừng:11-06 164030