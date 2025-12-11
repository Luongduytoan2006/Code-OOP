#include <iostream>
using namespace std;

class Exam
{
public:
    int prop;
    Exam(int = 1);
    Exam(const Exam&);
    ~Exam();
    const Exam& operator=(const Exam&);
};

Exam::Exam(int prop) : prop(prop)
{
    cout << "1";
}

Exam::Exam(const Exam& obj) : prop(obj.prop)
{
    cout << "2";
}

Exam::~Exam()
{
    cout << "2";
}

const Exam& Exam::operator=(const Exam& obj)
{
    if (this != &obj)
    {
        this->prop = obj.prop;
        cout << "3";
    }
    return *this;
}

Exam Func()
{
    Exam obj;
    return obj;
}

int main()
{
    Exam obj;
    obj = Func();
    return 0;
}
//Kết quả: 11322