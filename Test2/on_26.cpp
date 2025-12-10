#include <iostream>
using namespace std;

class Base {
    double x;
public:
    Base(double = 0.0);
    operator double();  // chuyển đối tượng -> double
    operator int();     // chuyển đối tượng -> int
};

Base::Base(double x) : x(x) {}

Base::operator double() {
    return this->x;     // trả về double
}

Base::operator int() {
    return int(this->x); // ép về int (cắt phần thập phân)
}

int main() {
    Base obj1(9.7), obj2(2.6);
    double x = double(obj1); // 9.7
    int y = int(obj2);       // 2
    cout << x << y;          // 9.72
    return 0;
}
