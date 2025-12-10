// CÂU 45
#include <iostream>
using namespace std;
class Base
{
    public:
        virtual void show(); // Hàm ảo: Cho phép đa hình (Polymorphism)
};
void Base::show()
{
    cout << "B";
}
class Derived : public Base
{
    public:
        void show(); // Ghi đè (Override) hàm của lớp cha
};
void Derived::show()
{
    cout << "D";
}
int main(void)
{
    Base *bp, b; // bp là con trỏ lớp cha
    Derived d;
    
    bp = &d; // bp trỏ tới đối tượng con (Derived)
    bp->show(); 
    // Do show() là virtual -> Cơ chế liên kết động (Dynamic Binding).
    // Trình biên dịch nhìn vào đối tượng thực tế mà bp trỏ tới (là d) -> Gọi Derived::show() -> In "D".
    
    bp = &b; // bp trỏ tới đối tượng cha (Base)
    bp->show(); 
    // Đối tượng thực tế là b (Base) -> Gọi Base::show() -> In "B".
    
    system("pause");
    return 0;
}

/**
A. Another Answer
B. Runtime Error
C. BD
D. Compile Error
E. DD
F. BB
G. DB -> ĐÚNG
*/