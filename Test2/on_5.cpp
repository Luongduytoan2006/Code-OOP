#include <iostream>
using namespace std;

class Base {
    int x;
public:
    Base(int = 1);
    int operator,(int);   // overload toán tử dấu phẩy
};

Base::Base(int x) : x(x) {}

int Base::operator,(int) {
    return this->x;      // trả về x của đối tượng bên trái
}

int main() {
    Base obj;            // x = 1 (theo mặc định)
    int x = 2;
    cout << (obj, x);    // gọi obj.operator,(x) -> in 1
    return 0;
}
