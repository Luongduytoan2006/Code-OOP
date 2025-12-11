#include <iostream>
using namespace std;

class Base
{
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
    cout << "2";
}

class Derived : public Base
{
public:
    Derived();
    ~Derived();
};

Derived::Derived()
{
    cout << "3";
}

Derived::~Derived()
{
    cout << "4";
}

int main()
{
    Derived obj;
    return 0;
}

// Kết quả: 1324
// Giải thích: Trong chương trình này, lớp cơ sở Base chứa một hàm tạo và một hàm hủy. Lớp dẫn xuất Derived cũng chứa một hàm tạo và một hàm hủy. Khi tạo một đối tượng của lớp dẫn xuất Derived, hàm tạo của lớp cơ sở Base sẽ được gọi trước, sau đó hàm tạo của lớp dẫn xuất Derived sẽ được gọi. Khi đối tượng kết thúc vòng đời của nó, hàm hủy của lớp dẫn xuất Derived sẽ được gọi trước, sau đó hàm hủy của lớp cơ sở Base sẽ được gọi. Do đó, kết quả là 1324.