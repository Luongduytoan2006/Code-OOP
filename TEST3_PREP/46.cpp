// CÂU 46
#include <iostream>
using namespace std;
class Base
{
    public:
        // LỖI BIÊN DỊCH (Compile Error): 
        // Trong C++, một hàm KHÔNG THỂ vừa là 'virtual' vừa là 'static'.
        // Lý do: Hàm static thuộc về lớp (không có con trỏ 'this'), trong khi hàm virtual cần đối tượng cụ thể để tra cứu bảng ảo (vtable).
        virtual static void Func(); 
};

void Base::Func()
{
    cout << "Base";
}

class Derived : public Base
{
    public:
        static void Func();
};

void Derived::Func()
{
    cout << "Derived";
}

int main()
{
    Base* ptr = new Base();
    Derived obj_b;
    ptr = &obj_b;
    ptr->Func();
    return 0;
}

/**
A. Compile Error -> ĐÚNG (Lỗi cú pháp "virtual static")
B. Another Answer
C. Derived
D. Runtime Error
E. Base
*/