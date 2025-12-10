// CÂU 8
#include "iostream" // Dùng ngoặc kép vẫn hợp lệ
using namespace std;

class Base
{
    int prop;
    public:
        Base(int = 0);
        void Func();
};

Base::Base(int prop) : prop(prop) 
{ }

void Base::Func()
{
    cout << this->prop;
}

class Derived : public Base
{
    int prop_d;
    public:
        Derived(int = 0);
        void Func();
};

Derived::Derived(int prop_d)
{
    // Lớp cha Base được khởi tạo mặc định (Base(0)) vì không được gọi tường minh trong init list.
    this->prop_d = prop_d;
}

void Derived::Func()
{
    cout << this->prop_d;
}

int main()
{
    Base obj_b(10);      // obj_b.prop = 10
    Base& obj_r = obj_b; // obj_r là tham chiếu tới obj_b
    
    Derived obj_d(20);   // obj_d.prop_d = 20. Phần Base bên trong obj_d có prop = 0 (do gọi mặc định)
    
    obj_r = obj_d;       
    // Object Slicing (Cắt đối tượng): Gán obj_d cho obj_b. 
    // Chỉ phần Base của obj_d (prop=0) được copy sang obj_b.
    // Lúc này obj_b.prop = 0. NHƯNG dòng này không ảnh hưởng tới obj_d.
    
    obj_d.Func();        
    // Gọi hàm Func của obj_d.
    // In ra prop_d của chính nó -> 20.
    
    return 0;
}

/**
A. Another Answer
B. Runtime Error
C. Compile Error
D. Garbage Value
E. 10
F. 20 -> ĐÚNG
*/