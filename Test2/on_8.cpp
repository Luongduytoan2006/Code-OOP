#include<iostream>
using namespace std;

class Exam {
    int prop;
public:
    Exam(int = 1);
    Exam(const Exam&);
    ~Exam();
    const Exam& operator=(const Exam&);
};

Exam::Exam(int prop) : prop(prop) {
    cout << "1";
}

Exam::Exam(Exam const& obj) : prop(obj.prop) {
    cout << "2";
}

Exam::~Exam() {}

const Exam& Exam::operator=(Exam const& obj) {
    if (this != &obj) {
        this->prop = obj.prop;
        cout << "3";
    }
    return *this;
}

Exam Func() {
    Exam obj;   // gọi constructor mặc định Exam(int=1)
    return obj; // trả về (return by value)
}

int main() {
    Exam obj;       // constructor mặc định
    obj = Func();   // gán
    return 0;
}
