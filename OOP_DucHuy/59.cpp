#include <iostream>
using namespace std;

class Exam
{
};

Exam::~Exam()
{
    cout << 'D';
}

int main()
{
    Exam* ptr = new Exam;
    delete ptr;
    return 0;
}
//Kết quả: compiled error
main.cpp:8:13: error: definition of implicitly-declared ‘Exam::~Exam()’
    8 | Exam::~Exam()
      |    