#include <iostream>
using namespace std;

class Exam
{
    int prop;

public:
    Exam();
    Exam(double);
    ~Exam();
    bool operator<(const Exam &);
};

Exam::Exam()
{
}

Exam::Exam(double prop)
    : prop(prop)
{
}

Exam::~Exam()
{
}

bool Exam::operator<(const Exam &obj)
{
    return obj.prop < this->prop ? true : false;
}

int main()
{
    Exam obj_x(10);
    Exam obj_y = Exam(14);
    (obj_x < obj_y) ? cout << "obj_x is small" : cout << "obj_y is small";
    return 0;
}

// Kết quả: obj_x is small
// Giải thích: Trong hàm main, obj_x.prop = 10, obj_y.prop = 14. Khi so sánh obj_x < obj_y, vì obj_x.prop < obj_y.prop nên kết quả là obj_x is small.