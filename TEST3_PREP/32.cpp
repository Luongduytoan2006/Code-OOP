// CÂU 32
#include <iostream>
using namespace std;

class Base
{
    int prop; // Biến prop của lớp cha
    public:
        Base();
        Base(int);
        ~Base();
        int getProp(); // Hàm getProp (chữ thường)
};

Base::Base() : prop(10) // Constructor mặc định: gán prop = 10
{ }

Base::Base(int prop) : prop(prop)
{ }

Base::~Base() { }

int Base::getProp()
{
    return this->prop; // Trả về prop của Base
}

class Derived : public Base
{
    int prop; // Biến prop của lớp con (Che khuất biến prop của cha)
    public:
        Derived(int);
        ~Derived();
        int GetProp(); // Hàm GetProp (chữ Hoa) -> Khác tên với hàm cha, không phải override
};

Derived::Derived(int prop) : prop(prop) 
// Chỉ khởi tạo prop của Derived = 100.
// KHÔNG gọi tường minh constructor Base, nên C++ tự động gọi Base() mặc định -> prop của Base = 10.
{ }

Derived::~Derived() { }

int Derived::GetProp()
{
    return this->prop; // Trả về prop của Derived
}

int main()
{
    Derived obj(100); 
    // Tại đây: Base::prop = 10, Derived::prop = 100.
    
    // 1. obj.getProp(): Gọi hàm kế thừa từ Base -> trả về Base::prop -> 10.
    // 2. obj.GetProp(): Gọi hàm của Derived -> trả về Derived::prop -> 100.
    cout << obj.getProp() << obj.GetProp();
    
    return 0;
}

/**
A. Compile Error
B. Runtime Error
C. Another Answer
D. 100100
E. 10100 -> ĐÚNG
F. 10010
G. 1010

Giải thích:
- Class `Derived` có biến `prop` riêng, che khuất `prop` của `Base`.
- Khi khởi tạo `obj(100)`, constructor `Base()` mặc định chạy trước -> gán `Base::prop` = 10. Sau đó `Derived` gán `Derived::prop` = 100.
- `obj.getProp()` (thường) là hàm của cha -> lấy 10.
- `obj.GetProp()` (hoa) là hàm của con -> lấy 100.
- Kết quả ghép chuỗi: 10100.
*/