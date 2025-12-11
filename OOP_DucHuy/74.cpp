#include <iostream>
using namespace std;

union Exam
{
    int var1;
    unsigned int var2;

    Exam();
    unsigned int getVar2();
};

Exam::Exam()
{
    this->var1 = 10;
}

unsigned int Exam::getVar2()
{
    return this->var2;
}

int main()
{
    Exam obj;
    cout << obj.getVar2();
    return 0;
}
//Kết quả: 10