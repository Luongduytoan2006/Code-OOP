// CÂU 4
#include <iostream>
using namespace std;
class Base
{
    int prop;
    public:
        virtual void Func() = 0; // Hàm thuần ảo (pure virtual) -> Base là lớp trừu tượng (Abstract Class)
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
    Base obj; 
    // LỖI BIÊN DỊCH (Compile Error): Không thể khởi tạo đối tượng từ lớp trừu tượng Base.
    // Muốn dùng phải khai báo con trỏ: Base* obj = new Derived();
    // Vì sao ? Vì lớp Base có hàm thuần ảo Func(), chưa được định nghĩa.
    // Hàm thuần ảo là bắt buộc gọi lớp con à ? Không, nhưng lớp con phải định nghĩa lại hàm đó.
    // Vậy tức cần thêm Base::Func(){} để định nghĩa hàm thuần ảo trong lớp Base à ? Không cần, vì hàm thuần ảo chỉ để buộc lớp con định nghĩa lại hàm đó.
    // Nên nếu không định nghĩa lại hàm đó trong lớp con, thì lớp con cũng trở thành lớp trừu tượng.
    obj.Func();
    return 0;
}

/**
A. No output
B. ITF
C. Another Answer
D. Runtime Error
E. Compile Error -> ĐÚNG (Lỗi khởi tạo object từ Abstract Class)
*/