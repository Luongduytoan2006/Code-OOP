#include <iostream>
using namespace std;

class Base1
{
public:
    Base1()
    {
        cout << "1";
    }
};

class Base2
{
public:
    Base2();
};

Base2::Base2()
{
    cout << "2";
}

class Derived : public Base1, public Base2
{
public:
    Derived();
};

Derived::Derived()
{
    cout << "3";
}

int main()
{
    Derived d;
    system("pause");
    return 0;
}

// Kết quả: 213
// Giải thích: Khi tạo một đối tượng của lớp dẫn xuất Derived, hàm khởi tạo của lớp cơ sở Base1 được gọi trước, sau đó hàm khởi tạo của lớp cơ sở Base2 được gọi và cuối cùng hàm khởi tạo của lớp dẫn xuất Derived được gọi. Do đó, kết quả là 213. Lưu ý rằng, hàm khởi tạo của lớp cơ sở được gọi theo thứ tự khai báo trong danh sách khai báo của lớp dẫn xuất.