#include <iostream>
using namespace std;
class Base
{
    int x;
    double y;

public:
    void Func(int = 0, double = 0.00, char = 'A');
    void Func(double, int = 10.00, char = 'Z');
    void Func(char, char, char);
};

void Base::Func(int x, double y, char z)
{
    this->x = x + int(y);
    cout << this->x;
}

void Base::Func(double x, int y, char z)
{
    this->x = z + z;
    this->y = x + y;
    cout << this->x;
}

void Base::Func(char x, char y, char z)
{
    this->x = x + y + z;
    this->y = double(x * 2);
    cout << this->x;
}

int main()
{
    Base obj;
    obj.Func(10 * 1.0, int(56.0));
    system("pause");
    return 0;
}

// Kết quả: 168
// Giải thích: Trong chương trình này, chúng ta định nghĩa ba phương thức Func() với các tham số khác nhau. Khi chúng ta gọi phương thức Func() với các giá trị tham số khác nhau, các phương thức sẽ được gọi tương ứng và giá trị của các thuộc tính x và y của đối tượng obj sẽ được cập nhật. Do đó, kết quả là 168.