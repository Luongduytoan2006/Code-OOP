#include <iostream>
using namespace std;
class Base
{
public:
    virtual void show() = 0;
};
class Derived : public Base
{
public:
    void show();
};
void Derived::show()
{
    cout << "Derived";
}
int main(void)
{
    Derived d;
    Base &br = d;
    br.show();
    system("pause");
    return 0;
}

// Kết quả: Derived
// Giải thích: Lớp cơ sở Base chứa một hàm ảo show() thuần ảo. Lớp dẫn xuất Derived cung cấp một triển khai cho hàm ảo này. Khi tạo một tham chiếu của lớp cơ sở Base và gán nó cho đối tượng của lớp dẫn xuất Derived, hàm show() của lớp dẫn xuất Derived sẽ được gọi khi gọi hàm show(). Do đó, kết quả là Derived.