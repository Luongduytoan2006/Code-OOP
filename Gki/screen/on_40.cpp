#include <iostream>
using namespace std;

class Exam {
    int prop;
public:
    Exam();
    Exam(double);
    ~Exam();
    bool operator==(const Exam& rhs) const;   // <-- PROTOTYPE cần thêm
};

Exam::Exam() { }

Exam::Exam(double prop) : prop(prop) { }     // gán double -> int (có thể bị truncate)

Exam::~Exam() { }

bool Exam::operator==(const Exam& rhs) const {
    return this->prop == rhs.prop;
}

int main() {
    Exam obj_x(10);           // 10 là int
    Exam obj_y = Exam(14);    // 14 là int
    (obj_x == obj_y) ? cout << "Equal" : cout << "Not Equal";
    return 0;
}
