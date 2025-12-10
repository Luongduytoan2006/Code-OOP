// CÂU 34
#include <iostream>
using namespace std;

class Base
{
    public:
        int prop_a;
        Base();
};

Base::Base() : prop_a(1) // Khởi tạo prop_a = 1
{ }

class Derived : public Base
{
    public:
        int prop_b;
        Derived();
};

Derived::Derived() : prop_b(2) // Khởi tạo prop_b = 2
{ }

void Func()
{
    Derived obj;
    throw obj; // Ném ra một ĐỐI TƯỢNG (Object) kiểu Derived (pass by value)
}

int main()
{
    try
    {
        Func();
    }
    // Catch 1: Bắt con trỏ (pointer) kiểu Derived*
    // LỖI LOGIC Ở ĐÂY: Chúng ta ném ra một "biến" (value), nhưng lại định bắt bằng "con trỏ" (pointer).
    // Do kiểu dữ liệu không khớp (Derived vs Derived*), block catch này bị BỎ QUA.
    catch (Derived *e) 
    {
        cout << e->prop_b;
    }
    // Catch 2: Bắt đối tượng kiểu Base (pass by value)
    // Vì Derived kế thừa Base, nên đối tượng Derived có thể được hứng bởi biến kiểu Base.
    // Hiện tượng Object Slicing (Cắt đối tượng) xảy ra: Chỉ phần Base (prop_a) được giữ lại.
    catch (Base e) 
    {
        cout << e.prop_a; // In ra prop_a là 1
    }
    return 0;
}

/**
A. 2
B. Runtime Error
C. Compile Error
D. 1 -> ĐÚNG
E. Another Answer

Giải thích:
1. `throw obj` ném ra một bản sao của đối tượng `Derived`.
2. `catch (Derived *e)` mong đợi một địa chỉ/con trỏ, nhưng nhận được một đối tượng -> Không khớp -> Bỏ qua.
3. `catch (Base e)` khớp vì `Derived` là con của `Base`. Đối tượng `Derived` bị ép kiểu về `Base`.
4. Chương trình chạy vào block này và in `e.prop_a` (giá trị là 1).
*/