// CÂU 24
#include <iostream>
using namespace std;
struct A
{
    // Trong C++, struct mặc định quyền truy cập là PUBLIC.
    // Khác với class (mặc định là private).
    int i;
    char j;
    float f;
    void func(); 
};
void A::func() { }

struct B
{
    public: // Khai báo tường minh public (dù không cần thiết với struct)
        int i;
        char j;
        float f;
        void func();
};
void B::func() { }

int main()
{
    A a; B b;
    // Các phép gán này đều HỢP LỆ vì các biến thành viên đều là public
    a.i = b.i = 1;
    a.j = b.j = 'c';
    a.f = b.f = 3.14159;
    
    a.func(); // Gọi hàm public -> OK
    b.func(); // Gọi hàm public -> OK
    
    cout << "Allocated"; // In ra chuỗi
    system("pause");
    return 0;
}

/**
A. Runtime Error
B. None of the mentioned
C. Compile Error
D. 3.14159
E. Allocated -> ĐÚNG

Giải thích:
- Điểm mấu chốt: Trong C++, các thành viên của `struct` mặc định là `public` (ngược với `class` mặc định là `private`).
- Do đó, việc truy cập trực tiếp `a.i`, `a.j`, `a.func()`... từ hàm `main` là hoàn toàn hợp lệ.
- Chương trình chạy bình thường và in ra "Allocated".
*/