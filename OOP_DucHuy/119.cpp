#include <iostream>
using namespace std;

class BaseA
{
public:
    BaseA();
    BaseA(const BaseA &);
    BaseA operator=(const BaseA &);
};

BaseA::BaseA()
{
    cout << "CBaseA.";
}

BaseA::BaseA(const BaseA &obj)
{
    cout << "CCBaseA.";
}

BaseA BaseA::operator=(const BaseA &obj)
{
    if (this == &obj)
        return *this;
    cout << "A0BaseA.";
    return *this;
}

class BaseB
{
    BaseA obj;

public:
    BaseB(BaseA &obj);
};

BaseB::BaseB(BaseA &obj) : obj(obj)
{
    cout << "CBaseB.";
}

int main()
{
    BaseA obj1;
    BaseB obj2(obj1);
    system("pause");
    return 0;
}

// Kết quả: CBaseA.CBaseB.
// Giải thích: Trong hàm main, obj1 được khởi tạo bằng hàm dựng không tham số của lớp BaseA. Khi khởi tạo obj2, obj2.obj được khởi tạo bằng obj1 nên kết quả là CBaseA.CBaseB.