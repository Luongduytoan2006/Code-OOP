// CÂU 44
#include <iostream>
using namespace std;
class Base
{
    public:
        void show(); // Hàm thường (không phải virtual)
};
void Base::show()
{
    cout << "B";
}
class Derived : public Base
{
    public:
        int x; // Biến x chỉ khai báo trong lớp Derived
        void show();
        Derived();
};
void Derived::show()
{
    cout << "D";
}
Derived::Derived() : x(10)
{ }
int main(void)
{
    Base *bp, b;
    Derived d;
    bp = &d; // Con trỏ lớp cha trỏ vào đối tượng lớp con (Hợp lệ)
    
    bp->show(); 
    // Do show() không phải hàm ảo -> Static Binding.
    // Gọi hàm dựa trên kiểu con trỏ (Base*) -> Gọi Base::show() -> In "B".
    
    // LỖI BIÊN DỊCH TẠI ĐÂY:
    // bp là con trỏ kiểu Base*. Class Base KHÔNG có thành viên 'x'.
    // Trình biên dịch không nhìn thấy biến 'x' của lớp con thông qua con trỏ cha.
    cout << bp->x; 
    
    return 0;
}

/**
A. Runtime Error
B. B10
C. Another Answer
D. Compile Error in line "cout << bp->x" -> ĐÚNG
E. D10
F. Compile Error in line "bp->show()"

Giải thích:
- Dòng `bp->show()` hợp lệ nhưng sẽ gọi hàm của lớp cha (in "B") vì không có cơ chế đa hình (virtual).
- Dòng `cout << bp->x` gây lỗi biên dịch vì con trỏ `bp` thuộc kiểu `Base`, mà class `Base` không hề chứa thuộc tính `x`. Muốn truy cập, phải ép kiểu con trỏ: `((Derived*)bp)->x`.
*/