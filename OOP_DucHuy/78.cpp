#include <iostream>
using namespace std;

class Exam
{
public:
    Exam(char = 'C');
    ~Exam();
};

Exam::Exam(char var)
{
    cout << var;
}

Exam::~Exam()
{
    cout << 'D';
}

int main()
{
    Exam obj;
    delete obj;
    return 0;
}
//Kết quả: Compiled error
main.cpp:24:12: error: type ‘class Exam’ argument given to ‘delete’, expected pointer
   24 |     delete obj;
      |            ^~~