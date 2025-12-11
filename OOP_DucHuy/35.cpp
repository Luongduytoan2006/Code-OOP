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
    catch (Derived *e)
    {
        cout << e->prop_b;
    }
    catch (Base e)
    {
        cout << e.prop_a;
    }
    return 0;
}

// Kết quả: 1
// Giải thích: Trong chương trình này, chúng ta đang cố gắng ném một đối tượng của lớp dẫn xuất Derived từ hàm Func(). Trong khối try-catch, chúng ta đã bắt ngoại lệ của lớp cơ sở Base và lớp dẫn xuất Derived. Tuy nhiên, trong trường hợp này, ngoại lệ được ném là một con trỏ của lớp dẫn xuất Derived, do đó nó không khớp với bất kỳ khối catch nào. Do đó, ngoại lệ sẽ được ném ra khỏi hàm main() và chương trình sẽ kết thúc với kết quả là 1.