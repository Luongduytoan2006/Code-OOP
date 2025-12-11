#include <iostream>
using namespace std;

class Base
{
    int x;

public:
    Base(int x = 1);
    friend void operator<<(ostream &o, Base obj);
};

Base::Base(int x) : x(x)
{
}

void operator<<(ostream &o, Base obj)
{
    o << obj.x;
}

int main()
{
    Base obj1(2), obj2;
    cout << obj1 << obj2;
    system("pause");
    return 0;
}

// Kết quả: 21
// Giải thích: Trong chương trình này, chúng ta định nghĩa một hàm toán tử << để hiển thị giá trị của một đối tượng của lớp cơ sở Base. Khi chúng ta sử dụng toán tử << để hiển thị giá trị của hai đối tượng obj1 và obj2, giá trị của thuộc tính x của mỗi đối tượng sẽ được hiển thị. Do đó, kết quả là 21.