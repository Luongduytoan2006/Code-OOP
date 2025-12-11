#include <iostream>
using namespace std;

class Base
{
    double prop_d;

public:
    Base();
    ~Base();
};

Base::Base()
{
    cout << "1";
}

Base::~Base()
{
}

class Derived : public Base
{
    int prop_i = 15;

public:
    Derived();
    ~Derived();
};

Derived::Derived()
{
    cout << "2";
}

Derived::~Derived()
{
}

int main()
{
    Derived obj;
    return 0;
}

// Kết quả: 12
// Giải thích: Khi tạo một đối tượng của lớp dẫn xuất Derived, hàm khởi tạo của lớp cơ sở Base được gọi trước, sau đó hàm khởi tạo của lớp dẫn xuất Derived được gọi. Do đó, kết quả là 12. Lưu ý rằng, hàm hủy của lớp cơ sở và lớp dẫn xuất cũng được gọi theo thứ tự ngược lại khi đối tượng bị hủy.
