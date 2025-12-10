// CÂU 27
#include <iostream>
#include <string>
using namespace std;
class Base{
    public:
        virtual string print() const;
};
string Base::print() const{
    return "B";
}
class Derived : public Base
{
    public:
        virtual string print() const;
};
string Derived::print() const
{
    return "D";
}

// LƯU Ý QUAN TRỌNG:
// Hàm này nhận tham số theo kiểu GIÁ TRỊ (Pass by Value), KHÔNG PHẢI tham chiếu (&) hay con trỏ (*).
void describe(Base p){
    cout << p.print();
}

int main()
{
    Base b;
    Derived d;
    
    describe(b); // Truyền Base -> p là Base -> In "B"
    
    describe(d); 
    // OBJECT SLICING (Cắt đối tượng):
    // Khi truyền một object con (Derived) vào tham số kiểu cha (Base) theo giá trị (value),
    // phần mở rộng của con sẽ bị "cắt bỏ", chỉ sao chép phần cha vào biến p.
    // Lúc này p trở thành một object Base thuần túy, mất tính đa hình.
    // -> Gọi hàm của Base -> In "B".
    
    system("pause");
    return 0;
}

/**
A. BB -> ĐÚNG (Do bị Object Slicing ở lần gọi thứ 2)
B. BD
C. Compile Error
D. DB
E. Runtime Error
F. Another Answer
*/