#include <iostream>
using namespace std;

class Base
{
    int x;

public:
    Base(int = 0);
    Base operator+(int);
    friend ostream &operator<<(ostream &, Base);
};

Base::Base(int x) : x(x)
{
}

Base Base::operator+(int x)
{
    Base obj;
    obj.x = this->x + x;
    return obj;
}

ostream &operator<<(ostream &o, Base obj)
{
    o << obj.x;
    return o;
}

int main()
{
    Base obj1(1), obj2;
    obj2 = obj1 + 2;
    cout << obj2;
    system("pause");
    return 0;
}

// Kết quả: 3
// Giải thích: Trong chương trình này, chúng ta định nghĩa một toán tử + để thực hiện phép cộng giữa một đối tượng của lớp Base và một số nguyên. Khi chúng ta thực hiện phép cộng obj1 + 2, một đối tượng tạm thời sẽ được tạo và giá trị của thuộc tính x của đối tượng này sẽ được cập nhật. Sau đó, đối tượng tạm thời này sẽ được gán cho đối tượng obj2. Khi chúng ta in ra giá trị của đối tượng obj2, giá trị 3 sẽ được hiển thị. Do đó, kết quả là 3.