// CÂU 22
#include <iostream>
using namespace std;

class Base
{
    double prop_b;
    public:
        virtual void Func(); // Hàm ảo: Cho phép ghi đè và đa hình
};

void Base::Func()
{
    cout << "1";
}

class Derived : public Base
{
    int prop_d = 15; // Khởi tạo ngay khi khai báo (Valid từ C++11 trở đi)
    public:
        void Func(); // Ghi đè hàm Func của Base
};

void Derived::Func()
{
    cout << "2";
}

int main()
{
    Base* ptr = new Base(); // ptr trỏ đến đối tượng Base trên heap
    Derived obj;            // obj là đối tượng Derived trên stack
    
    ptr = &obj;             // ptr đổi hướng, trỏ sang obj (Derived)
    
    ptr->Func();            
    // Do Func là virtual và ptr đang trỏ tới đối tượng Derived
    // -> Gọi hàm Derived::Func() (Dynamic Binding) -> In ra "2"
    
    return 0;
}

/**
A. Another Answer
B. 2 -> ĐÚNG
C. 1
D. Runtime Error
E. Compile Error

Giải thích:
- Đây là ví dụ kinh điển về Đa hình (Polymorphism).
- Hàm `Func` được khai báo `virtual` ở lớp cha.
- Khi con trỏ lớp cha (`ptr`) trỏ vào đối tượng lớp con (`obj`), việc gọi hàm `ptr->Func()` sẽ kích hoạt cơ chế liên kết động (dynamic binding), chạy hàm của lớp con thực sự đang được trỏ tới.
*/