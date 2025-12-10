// CÂU 13
#include <iostream>
using namespace std;
class Base
{
    int prop_b;
    public:
        void setPropB(int);
        void printPropB();
};
void Base::setPropB(int prop_b)
{
    this->prop_b = prop_b;
}
void Base::printPropB()
{
    cout << this->prop_b;
}

// Kế thừa PRIVATE: Các thành viên public/protected của Base 
// sẽ trở thành PRIVATE trong Derived.
class Derived : private Base 
{
    int prop_d;
    public:
        void setPropD(int, int);
        void printPropD();
};

void Derived::setPropD(int prop_b, int prop_d)
{
    // Dù kế thừa Private, nhưng bên trong class Derived vẫn gọi được hàm của cha.
    setPropB(prop_b); 
    this->prop_d = prop_d;
}
void Derived::printPropD()
{
    printPropB(); // In ra prop_b (10)
    cout << this->prop_d; // In ra prop_d (20)
}
int main()
{
    Derived obj;
    // Các hàm setPropD và printPropD là public của Derived nên main gọi được bình thường.
    obj.setPropD(10, 20); 
    obj.printPropD(); // Kết quả: 1020
    return 0;
}

/**
A. Another Answer
B. 10
C. 1020 -> ĐÚNG
D. Compile Error
E. Runtime Error
F. 20
G. 2010

Giải thích:
- Hàm `setPropD` gọi `setPropB` gán prop_b = 10, sau đó gán prop_d = 20.
- Hàm `printPropD` gọi `printPropB` (in 10) sau đó in prop_d (20).
- Kết quả ghép lại là 1020.
- Lưu ý: Dù kế thừa `private`, nhưng các hàm `setPropD` và `printPropD` được khai báo `public` trong `Derived` nên `main` truy cập được.
*/