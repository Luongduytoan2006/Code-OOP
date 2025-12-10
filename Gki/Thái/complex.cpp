#include <iostream>
using namespace std;

class Complex {
    double R, I;
public:
    Complex(double R, double I): R(R), I(I) {}
    Complex(double R) { this->R = this->I = R; }   // ctor 1 tham số    
    friend Complex operator+(Complex, Complex);
    friend ostream& operator<<(ostream&, Complex);
};

Complex operator+(Complex a, Complex b) {
    return Complex(a.R + b.R, a.I + b.I);
}
ostream& operator<<(ostream& o, Complex c) {
    o << c.R << "," << c.I;
    return o;
}

int main() {
    Complex obj1(3, 4);
    Complex obj2 = obj1 + 6; // 6 -> Complex(6) nhờ ctor 1 tham số
    cout << obj2;
    return 0;
}
