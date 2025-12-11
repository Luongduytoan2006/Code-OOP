#include <iostream>
using namespace std;

class Base
{
    int prop;

public:
    virtual void Func() = 0;
};

class Derived : public Base
{
public:
    void Func();
};

void Derived::Func()
{
    cout << "ITF";
}

int main()
{
    Derived obj;
    obj.Func();
    return 0;
}

// Kết quả: ITF
// Giải thích: Lớp cơ sở Base chứa một hàm ảo thuần ảo Func(). Lớp dẫn xuất Derived cung cấp một triển khai cho hàm ảo này. Khi gọi hàm Func() trên một đối tượng của lớp dẫn xuất Derived, hàm Func() của lớp dẫn xuất Derived sẽ được gọi. Do đó, kết quả là ITF.