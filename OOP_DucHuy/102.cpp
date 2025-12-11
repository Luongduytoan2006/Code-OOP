#include <iostream>
using namespace std;

class Base
{
    int x;

public:
    Base(int = 1);
    int operator,(int);
};

Base::Base(int x) : x(x)
{
}

int Base::operator,(int x)
{
    return x;
}

int main()
{
    Base obj;
    int x = 2;
    cout << (obj, x);
    system("pause");
    return 0;
}

// Kết quả: 2
// Giải thích: Trong chương trình này, chúng ta định nghĩa một toán tử , để trả về giá trị của một đối tượng của lớp Base. Khi chúng ta sử dụng toán tử , để trả về giá trị của đối tượng obj, giá trị của biến x sẽ được trả về. Do đó, kết quả là 2.