#include <iostream>
#include <cmath>
using namespace std;

class Complex {
    double R;
    double I;
public:
    Complex(double = 0.0, double = 0.0);
    ~Complex();
    double Func();
    operator double();
private:
    double getFunc();
};

Complex::Complex(double R, double I) : R(R), I(I) { }
Complex::~Complex() { }

double Complex::Func() { return getFunc(); }
Complex::operator double() { return getFunc(); }
double Complex::getFunc() { return sqrt(this->R * this->R + this->I * this->I); }

int main() {
    Complex obj{3.0, 4.0};
    cout << obj.Func() << obj;
    return 0;
}
