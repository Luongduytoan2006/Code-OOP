#include <iostream>
using namespace std;

class Base {
    int x; 
    double y;
public:
    void Func(int x = 0, double y = 0.00, char z = 'A');
    void Func(double x, int y = 10.00, char z = 'Z');
    void Func(char x, char y, char z);
};

void Base::Func(int x, double y, char z) {
    this->x = x + int(y);
    cout << this->x;
}

void Base::Func(double x, int y, char z) {
    this->x = z + z;          // 'Z' = 90 -> 180
    this->y = x + y;          // không in ra y
    cout << this->x;
}

void Base::Func(char x, char y, char z) {
    this->x = x + y + z;
    this->y = double(x * 2);
    cout << this->x;
}

int main() {
    Base obj;
    obj.Func(10 * 1.0, int(56.0));  // chọn overload (double, int, char='Z')
    return 0;
}
