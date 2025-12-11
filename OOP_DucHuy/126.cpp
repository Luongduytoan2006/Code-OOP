#include <iostream>
using namespace std;

class Base
{
    int x, y;

public:
    Base(int x = 0, int y = 0);
    Base operator+(Base);
    friend ostream &operator<<(ostream &, const Base &);
};

Base::Base(int x, int y) : x(x), y(y)
{
}

Base Base::operator+(Base obj)
{
    Base temp;
    temp.x = x + obj.x;
    temp.y = y + obj.y;
    return temp;
}

ostream &operator<<(ostream &o, const Base &obj)
{
    o << obj.x << obj.y;
    return o;
}

int main()
{
    Base obj1(90, 80);
    Base obj2(10, 20);
    Base obj3;
    Base obj4 = obj3;
    obj4 = obj1 + obj2;
    cout << obj4;
    system("pause");
    return 0;
}

// Kết quả: 100100
// Giải thích: Trong hàm main, obj1.x = 90, obj1.y = 80, obj2.x = 10, obj2.y = 20. Khi gọi hàm obj1 + obj2, obj4.x = obj1.x + obj2.x = 90 + 10 = 100, obj4.y = obj1.y + obj2.y = 80 + 20 = 100. Do đó kết quả là 100100.