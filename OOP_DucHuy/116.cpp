#include <iostream>
using namespace std;

class Exam
{
    int var;

public:
    explicit Exam(int);
    ~Exam();
    int getVar();
};

Exam::Exam(int var)
    : var(var)
{
}

Exam::~Exam()
{
}

int Exam::getVar()
{
    return this->var;
}

int main()
{
    Exam obj1 = 1;
    Exam obj2 = obj1;
    cout << obj1.getVar() << obj2.getVar();
    return 0;
}

// Kết quả: 11
// Giải thích: Trong hàm main, obj1 được khởi tạo với giá trị 1. Khi khởi tạo obj2 bằng obj1, obj2 sẽ được khởi tạo với giá trị của obj1 nên kết quả là 11.