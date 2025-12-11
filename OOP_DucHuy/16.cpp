#include <iostream>
using namespace std;

class Base
{
public:
    virtual void show();
};

void Base::show()
{
    cout << "B";
}

class Derived : public Base
{
public:
    void show();
};

void Derived::show()
{
    cout << "D";
}

int main()
{
    Base *bp = new Derived;
    bp->Base::show();
    system("pause");
    return 0;
}

// Kết quả: B
// Giải thích: Khi con trỏ bp trỏ đến một đối tượng của lớp dẫn xuất Derived, hàm show() của lớp dẫn xuất Derived được gọi. Tuy nhiên, trong hàm main(), hàm show() của lớp cơ sở Base được gọi thông qua phạm vi giới hạn. Do đó, kết quả là B. Lưu ý rằng, hàm show() của lớp cơ sở Base có thể được ghi đè trong lớp dẫn xuất Derived.