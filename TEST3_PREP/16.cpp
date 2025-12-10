// CÂU 16
#include <iostream>
#include <string>
using namespace std;

class Base
{
    public:
        // LỖI BIÊN DỊCH (Compile Error):
        // C++ KHÔNG hỗ trợ "Virtual Constructor". 
        // Constructor không thể là hàm ảo. Chỉ có Destructor mới nên là virtual.
        virtual Base(); 
};

Base::Base()
{
    cout << "Base";
}

class Derived : public Base
{
    public:
        // Lỗi cú pháp: Không thể khai báo hàm tên Base() trong class Derived
        // (Nếu là constructor thì phải tên là Derived).
        Base(); 
};

Derived::Base()
{
    cout << "Derived";
}

int main()
{
    Base obj;
    return 0;
}

/**
A. Derived
B. Base
C. Compile Error -> ĐÚNG (Lỗi do khai báo virtual constructor)
D. Runtime Error
E. Another Answer
*/