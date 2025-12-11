#include <iostream>

using namespace std;

class Complex {
public:
    int R, I;
    Complex(int = 0, int = 0);
    friend ostream& operator<<(ostream&, const Complex&);
};

Complex::Complex(int R, int I) : R(R), I(I) {} 

ostream& operator<<(ostream& o, const Complex& obj) {
    o << obj.R << "+" << obj.I << "i"; 
    return o;
}

int main() {
    Complex obj(10, 15);
    cout << "obj: " << obj; 
    system("pause");
    return 0;
}
//Kết quả: obj: 10+15i