#include <iostream>
using namespace std;

class Complex
{
    double R, I;

public:
    Complex(double = 1.0, double = 2.0);
    Complex operator+(Complex);
    friend ostream &operator<<(ostream &, Complex);
};

Complex::Complex(double R, double I) : R(R)
{
    this->I = I;
}

Complex Complex::operator+(Complex obj)
{
    return Complex(this->R + obj.R, this->I + obj.I);
}

ostream &operator<<(ostream &o, Complex obj)
{
    o << obj.R << "," << obj.I;
    return o;
}

int main()
{
    Complex obj1;
    Complex obj2(2.0, 3.0);
    obj2.operator+(obj1);
    cout << obj2;
    system("pause");
    return 0;
}

// Kết quả: 2,3
// Giải thích: Trong chương trình này, chúng ta định nghĩa một lớp Complex để biểu diễn số phức với phần thực và ảo. Chúng ta cũng định nghĩa một toán tử + để thực hiện phép cộng giữa hai số phức. Khi chúng ta thực hiện phép cộng obj2 + obj1, một đối tượng tạm thời sẽ được tạo và giá trị của phần thực và ảo của đối tượng này sẽ được cập nhật. Tuy nhiên, giá trị của đối tượng tạm thời này không được gán cho đối tượng obj2. Do đó, khi chúng ta in ra giá trị của đối tượng obj2, giá trị mặc định của nó (2,3) sẽ được hiển thị. Do đó, kết quả là "2,3".