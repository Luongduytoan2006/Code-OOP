#include <iostream>
using namespace std;
struct A
{
    int i;
    char j;
    float f;
    void func();
};
void A::func()
{
}
struct B
{
public:
    int i;
    char j;
    float f;
    void func();
};
void B::func()
{
}
int main()
{
    A a;
    B b;
    a.i = b.i = 1;
    a.j = b.j = 'c';
    a.f = b.f = 3.14159;
    a.func();
    b.func();
    cout << "Allocated";
    system("pause");
    return 0;
}

// Kết quả: Allocated
// Giải thích: Cả struct A và struct B đều chứa các thành viên dữ liệu giống nhau, nhưng chúng khác nhau về quyền truy cập mặc định. Các thành viên dữ liệu của struct A được khai báo là private, trong khi các thành viên dữ liệu của struct B được khai báo là public. Do đó, các thành viên dữ liệu của struct A không thể truy cập từ bên ngoài struct, trong khi các thành viên dữ liệu của struct B có thể truy cập từ bên ngoài struct. Trong trường hợp này, các thành viên dữ liệu i, j và f của cả struct A và struct B được gán giá trị và hàm func() của cả struct A và struct B được gọi. Do đó, kết quả là Allocated.