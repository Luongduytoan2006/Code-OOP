#include <iostream>
using namespace std;

class Exam
{
    double prop_x, prop_y, prop_z;
    double result;

public:
    Exam(double = 0, double = 0, double = 0);
    ~Exam();
    void Func(int);
};

Exam::Exam(double prop_x, double prop_y, double prop_z)
    : prop_x(prop_x), prop_y(prop_y), prop_z(prop_z)
{
}

Exam::~Exam()
{
}

void Exam::Func(int prop_x)
{
    this->result = (this->prop_x == 0) ? 3.14f * this->prop_z * this->prop_z : prop_x * this->prop_y;
    cout << this->result;
}

int main()
{
    Exam obj(10, 10, 20);
    obj.Func(0);
    return 0;
}

// Kết quả: 1256
// Giải thích: Khi gọi hàm Func, prop_x = 0, prop_y = 10, prop_z = 20. Vì prop_x = 0 nên result = 3.14 * prop_z * prop_z = 3.14 * 20 * 20 = 1256.