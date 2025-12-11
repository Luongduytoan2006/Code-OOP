#include <iostream>
using namespace std;
class Base
{
public:
    virtual void Func();
};
void Base::Func()
{
    cout << "Base";
}
class Derived : public Base
{
private:
    void Func();
};
void Derived::Func()
{
    cout << "Derived";
}
int main()
{
    Base *ptr = new Base();
    Derived obj;
    ptr = &obj;
    ptr->Func();
    return 0;
}

// Kết quả: Derived
// Giải thích: Khi con trỏ ptr được khởi tạo với địa chỉ của đối tượng obj, hàm Func() của lớp dẫn xuất Derived được gọi. Do đó, kết quả là Derived. Lưu ý rằng, hàm Func() của lớp cơ sở Base được định nghĩa là hàm ảo. Do đó, nó có thể được ghi đè trong lớp dẫn xuất.