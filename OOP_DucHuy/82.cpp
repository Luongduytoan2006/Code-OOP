#include <iostream>
using namespace std;

class Complex
{
public:
    int R;
    int I;

    Complex();
    Complex(int, int);
    ~Complex();
    Complex operator+(const Complex&);
    void operator+(const Complex&);
    friend ostream& operator<<(ostream&, const Complex&);
};

Complex::Complex() {}

Complex::Complex(int R, int I) : R(R), I(I) {}

Complex::~Complex() {}

Complex Complex::operator+(const Complex& obj)
{
    return Complex(this->R + obj.R, this->I + obj.I);
}

void Complex::operator+(const Complex& obj)
{
    Complex temp(this->R + obj.R, this->I + obj.I);
    cout << temp;
}

ostream& operator<<(ostream& o, const Complex& obj)
{
    o << obj.R << "+" << obj.I << "i";
    return o;
}

int main()
{
    Complex obj_x(1, 2), obj_y(3, 4);
    obj_x + obj_y; 
    return 0;
}
//Kết quả: Compiled error
main.cpp:14:10: error: ‘void Complex::operator+(const Complex&)’ cannot be overloaded with ‘Complex Complex::operator+(const Complex&)’
   14 |     void operator+(const Complex&);
      |          ^~~~~~~~
main.cpp:13:13: note: previous declaration ‘Complex Complex::operator+(const Complex&)’
   13 |     Complex operator+(const Complex&);
      |             ^~~~~~~~
main.cpp:29:6: error: no declaration matches ‘void Complex::operator+(const Complex&)’
   29 | void Complex::operator+(const Complex& obj)
      |      ^~~~~~~
main.cpp:24:9: note: candidate is: ‘Complex Complex::operator+(const Complex&)’
   24 | Complex Complex::operator+(const Complex& obj)
      |         ^~~~~~~
main.cpp:4:7: note: ‘class Complex’ defined here
    4 | class Complex
      |       ^~~~~~~