// CÂU 5
#include <iostream>
using namespace std;
class Base
{
    public:
        int x, y;
        Base(int, int);
};
Base::Base(int i, int j)
{
    this->x = i;
    this->y = j;
}
class Derived : public Base
{
    public:
        Derived(int, int);
        void print();
};

// LỖI TẠI ĐÂY:
// 1. Không thể khởi tạo trực tiếp thành viên của lớp cha (x, y) trong danh sách khởi tạo (initializer list) của lớp con.
// 2. Lớp Base không có constructor mặc định (chỉ có Base(int, int)), nên lớp con PHẢI gọi constructor của lớp cha.
// Cách sửa đúng: Derived::Derived(int i, int j) : Base(i, j) { }
Derived::Derived(int i, int j) : x(i), y(j) 
{ }

void Derived::print()
{
    cout << this->x << this->y;
}

int main(void)
{
    Derived q(10, 10); // Lỗi biên dịch xảy ra trước khi chạy dòng này
    q.print();
    system("pause");
    return 0;
}

/**
A. Runtime Error
B. Another Answer
C. 00
D. Compile Error -> ĐÚNG (Lỗi cú pháp trong constructor Derived)
E. 1010
*/