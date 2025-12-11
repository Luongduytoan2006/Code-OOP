#include <iostream>
using namespace std;
class Base
{
    int x;

public:
    Base(int x = 1);
    friend void operator<<(ostream &, Base &);
};

Base::Base(int x) : x(x)
{
}

void operator<<(ostream &o, Base &obj)
{
    o << obj.x;
}

int main()
{
    Base obj(2);
    cout << obj;
    system("pause");
    return 0;
}

// Kết quả: 2
// Giải thích: Trong chương trình này, chúng ta định nghĩa một hàm toán tử << để hiển thị giá trị của một đối tượng của lớp cơ sở Base. Khi chúng ta sử dụng toán tử << để hiển thị giá trị của đối tượng obj, giá trị của thuộc tính x của đối tượng obj sẽ được hiển thị. Do đó, kết quả là 2.