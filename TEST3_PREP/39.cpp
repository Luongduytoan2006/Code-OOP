// CÂU 39
#include <iostream>
using namespace std;

class Base
{
    int prop; // Biến private, mặc định khởi tạo rác nếu không có constructor
    public:
        Base();
        void Func();
};

Base::Base() : prop(0) // Constructor khởi tạo prop = 0
{
}

void Base::Func()
{
    // Hàm này thuộc class Base nên có quyền truy cập biến private 'prop'
    this->prop++; // Tăng từ 0 lên 1
    cout << this->prop; // In ra 1
}

class Derived : public Base // Kế thừa public từ Base
{
    // Derived kế thừa hàm Func() từ Base
};

int main()
{
    Derived obj; // Khởi tạo obj -> Gọi constructor Base() -> prop = 0
    obj.Func();  // Gọi hàm Func kế thừa -> prop tăng lên 1 và in ra
    return 0;
}

/**
A. Runtime Error
B. Compile Error
C. 1 -> ĐÚNG
D. 0
E. Another Answer

Giải thích:
- Đối tượng `obj` được tạo, constructor lớp cha chạy, gán `prop = 0`.
- Hàm `Func()` được gọi, tăng `prop` lên 1 và in ra màn hình.
- Kết quả là 1.
*/