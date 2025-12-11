#include <iostream>
using namespace std;
class Base
{
public:
    int prop_a;
    Base();
};
Base::Base()
    : prop_a(1)
{
}
class Derived : public Base
{
public:
    int prop_b;
    Derived();
};
Derived::Derived()
    : prop_b(2)
{
}
void Func()
{
    Derived obj;
    throw obj;
}
int main()
{
    try
    {
        Func();
    }
    catch (Derived e)
    {
        cout << e.prop_b;
    }
    catch (Base e)
    {
        cout << e.prop_a;
    }
    return 0;
}

// Kết quả: 2
// Giải thích: Khi hàm Func() được gọi, một đối tượng của lớp dẫn xuất Derived được tạo và ném ra. Trong khối try-catch, ngoại lệ được ném ra được bắt bởi các khối catch theo thứ tự. Trong trường hợp này, ngoại lệ được ném ra là một đối tượng của lớp dẫn xuất Derived, do đó nó sẽ được bắt bởi khối catch của lớp dẫn xuất Derived. Do đó, giá trị của prop_b được hiển thị, kết quả là 2. Lưu ý rằng, nếu khối catch của lớp dẫn xuất Derived không được cung cấp, ngoại lệ sẽ được bắt bởi khối catch của lớp cơ sở Base và prop_a sẽ được hiển thị.