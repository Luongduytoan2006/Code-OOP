#include <iostream>
using namespace std;

class Exam {
    int prop;
public:
    Exam(int = 1);
    ~Exam();
    const Exam operator+(const Exam&) const;
    Exam& operator+=(const Exam&);
    friend ostream& operator<<(ostream&, const Exam&);
};

Exam::Exam(int prop) : prop(prop) {}
Exam::~Exam() {}

const Exam Exam::operator+(const Exam& obj) const {
    return Exam(this->prop + obj.prop);
}

Exam& Exam::operator+=(const Exam& obj) {
    this->prop += obj.prop;
    return *this;
}

ostream& operator<<(ostream& o, const Exam& obj) {
    o << obj.prop;
    return o;
}

int main() {
    Exam obj_x, obj_y(2), obj_z(3);
    obj_z += obj_x + obj_y;   // 3 += (1+2) -> 6
    cout << obj_x << obj_y << obj_z; // 126
    return 0;
}
