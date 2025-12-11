#include <iostream>
using namespace std;

class Base
{
    int x;

public:
    Base(int x = 1) : x(x) {}
    friend int operator,(Base &, int);
};

int operator,(Base &o, int x)
{
    return x;
}

int main()
{
    Base obj;
    int x = 2;
    cout << operator,(obj, x);
    system("pause");
    return 0;
}

// Kết quả: 2
// Giải thích: Trong hàm main, obj là một đối tượng của lớp Base, x = 2. Khi gọi hàm operator,(obj, x) thì hàm operator, sẽ trả về giá trị của x nên kết quả là 2.