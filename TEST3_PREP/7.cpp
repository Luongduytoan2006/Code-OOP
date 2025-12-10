// CÂU 7
#include <iostream>
using namespace std;
class Base
{
    public:
        virtual void Func();
};
void Base::Func()
{
    cout << "B";
}
class Derived : public Base
{
    int prop;
    public:
        void Func();
        Derived();
        int getProp() const;
};
void Derived::Func()
{
    cout << "D";
}
Derived::Derived()
{
    this->prop = 10;
}
int Derived::getProp() const
{
    return this->prop;
}
int main()
{
    Derived obj_d;
    Base* ptr = &obj_d; // Con trỏ cha trỏ tới đối tượng con
    ptr->Func(); // Hàm ảo (virtual) -> Dynamic binding -> Gọi Derived::Func() -> in "D"

    // LỖI BIÊN DỊCH (Compile Error) TẠI ĐÂY:
    // 'ptr' là con trỏ kiểu Base*. Class Base KHÔNG hề có phương thức getProp().
    // Trình biên dịch chỉ kiểm tra trong phạm vi class Base.
    cout << ptr->getProp(); 
    
    return 0;
}

/**
A. D10
B. Compile Error -> ĐÚNG (Do gọi hàm của lớp con thông qua con trỏ lớp cha mà hàm đó không khai báo ở cha)
*/