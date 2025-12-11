#include <iostream>
using namespace std;

class Base
{
public:
    virtual void Func() const = 0;
};

class DerivedA : public Base
{
public:
    void Func() const;
};

void DerivedA::Func() const
{
    cout << "1";
}

class DerivedB : public Base
{
public:
    void Func() const;
};

void DerivedB::Func() const
{
    cout << "2";
}

class Derived : public DerivedA, public DerivedB
{
public:
    void Func() const;
};

void Derived::Func() const
{
    DerivedB::Func();
}

int main()
{
    int var_i;
    Derived obj;
    DerivedA obj_a;
    DerivedB obj_b;
    Base *arr[3];
    arr[0] = &obj;
    arr[1] = &obj_a;
    arr[2] = &obj_b;
    arr[var_i]->Func();
    return 0;
}

// Kết quả: Compiler Error
// Giải thích: Lớp Derived kế thừa từ lớp DerivedA và lớp DerivedB, mỗi lớp này đều ghi đè hàm ảo Func() của lớp cơ sở Base. Khi tạo một mảng con trỏ đến lớp cơ sở Base và gán các con trỏ này cho các đối tượng của lớp dẫn xuất, chương trình không biên dịch được vì không thể xác định được đối tượng nào sẽ được gọi khi gọi hàm Func(). Điều này dẫn đến lỗi không xác định.