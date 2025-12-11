#include <iostream>
using namespace std;

class Base
{
public:
    virtual void Func();
};

void Base::Func()
{
    cout << "Base";
}

class Derived : public Base
{
public:
    void Func();
};

void Derived::Func()
{
    cout << "Derived";
}

class DerivedA : public Derived
{
public:
    void Func();
};

void DerivedA::Func()
{
    cout << "DerivedA";
}

class DerivedB : public Derived
{
public:
    void Func();
};

void DerivedB::Func()
{
    cout << "DerivedB";
}

int main()
{
    Base *ptr;
    DerivedA obj_a;
    DerivedB obj_b;
    ptr = &obj_a;
    ptr->Func();
    return 0;
}

// Kết quả: DerivedA
// Giải thích: Lớp cơ sở Base chứa một hàm ảo Func(). Lớp dẫn xuất Derived cung cấp một triển khai cho hàm ảo này. Lớp dẫn xuất DerivedA và DerivedB cũng cung cấp triển khai cho hàm ảo này. Khi tạo một con trỏ của lớp cơ sở Base và trỏ tới đối tượng của lớp dẫn xuất DerivedA, hàm Func() của lớp dẫn xuất DerivedA sẽ được gọi. Do đó, kết quả là DerivedA.