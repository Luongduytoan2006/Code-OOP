#include <iostream>
using namespace std;
class Base
{
protected:
    int prop_x, prop_y;

public:
    void setProp(int, int);
    virtual int area() = 0;
};
void Base::setProp(int prop_x, int prop_y)
{
    this->prop_x = prop_x;
    this->prop_y = prop_y;
}
class DerivedA : public Base
{
public:
    int area();
};
int DerivedA::area()
{
    return (prop_x * prop_y);
}
class DerivedB : public Base
{
public:
    int area();
};
int DerivedB::area()
{
    return (this->prop_x * this->prop_y / 2);
}
int main()
{
    DerivedA obj_a;
    DerivedB obj_b;
    Base *ptr_x = &obj_a;
    Base *ptr_y = &obj_b;
    ptr_x->setProp(4, 5);
    ptr_y->setProp(4, 5);
    cout << ptr_x->area();
    cout << ptr_y->area();
    return 0;
}

// Kết quả: 2010
// Giải thích: Lớp cơ sở Base chứa hai thuộc tính prop_x và prop_y và một phương thức setProp() để thiết lập giá trị cho hai thuộc tính này. Lớp dẫn xuất DerivedA và DerivedB cung cấp triển khai cho phương thức area() để tính diện tích của hình chữ nhật và tam giác. Khi tạo một con trỏ của lớp cơ sở Base và trỏ tới đối tượng của lớp dẫn xuất DerivedA, phương thức area() của lớp dẫn xuất DerivedA sẽ được gọi để tính diện tích của hình chữ nhật. Khi tạo một con trỏ khác của lớp cơ sở Base và trỏ tới đối tượng của lớp dẫn xuất DerivedB, phương thức area() của lớp dẫn xuất DerivedB sẽ được gọi để tính diện tích của tam giác. Do đó, kết quả là 20 10.