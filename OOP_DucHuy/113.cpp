#include <iostream>
using namespace std;

class Exam
{
public:
    Exam();
    Exam(int);
    ~Exam();
};

Exam::Exam()
{
    cout << "C1";
}

Exam::Exam(int var)
{
    cout << "C2";
}

Exam::~Exam()
{
    cout << "D";
}

void Func()
{
    Exam();
    Exam(1);
}

int main()
{
    Func();
    return 0;
}

// Kết quả: C1C2
// Giải thích: Trong hàm Func, khi gọi Exam() thì sẽ gọi hàm dựng không tham số, khi gọi Exam(1) thì sẽ gọi hàm dựng có tham số. Do đó kết quả là C1C2.