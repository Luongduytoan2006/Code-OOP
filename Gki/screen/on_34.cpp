#include <iostream>
using namespace std;

class Exam {
public:
    int prop;
    Exam(int = 0);
    int& operator[](const int&);
    int  operator[](const int&) const;
};

Exam::Exam(int prop) : prop(prop) {}

int& Exam::operator[](const int& index) { cout << "0"; return this->prop; }
int  Exam::operator[](const int& index) const { cout << "1"; return this->prop; }

void Func(const Exam& obj) {
    int var_x = obj[2];
}

int main() {
    Exam obj(7);
    obj[3] = 8; // gọi operator[] non-const, in "0"
    cout<<obj[5]; // gọi operator[] non-const, in "0" rồi in giá trị prop (vì nó return tham chiếu)
    int var_x = obj[2];
    Func(obj);
    return 0;
}
