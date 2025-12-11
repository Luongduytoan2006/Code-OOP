#include <iostream>
using namespace std;

class Base
{
    int x, y;

public:
    Base(int, int);
    void Show();
};

Base::Base(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Base::Show()
{
    cout << this->x << this->y;
}

int main()
{
    int x = 1;
    int &y = x;
    Base obj(y, x);
    system("pause");
    return 0;
}

// Kết quả: 11
// Giải thích: Trong hàm main, x = 1, y = x = 1. Khi khởi tạo obj, obj.x = y = 1, obj.y = x = 1. Khi gọi hàm Show, obj.x = 1, obj.y = 1 nên kết quả là 11.