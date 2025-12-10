#include <iostream>
using namespace std;

class Exam {
    int prop;
public:
    Exam();
    Exam(double);
    ~Exam();
    bool operator<(const Exam&);
};

Exam::Exam() { }

Exam::Exam(double prop) : prop(prop) { }

Exam::~Exam() { }

bool Exam::operator<(const Exam& obj) {
    return obj.prop < this->prop ? true : false;  // Bẫy logic: this->prop < obj.prop mới đúng
}

int main() {
    Exam obj_x(10);
    Exam obj_y = Exam(14);
    (obj_x < obj_y) ? cout << "obj_x is small" : cout << "obj_y is small";
    return 0;
}
