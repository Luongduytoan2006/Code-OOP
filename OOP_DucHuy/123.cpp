#include <iostream>
using namespace std;

class Exam
{
    static int count;

public:
    ~Exam();
    void Func();
};

int Exam::count = 5;

Exam::~Exam()
{
    Exam::count--;
}

void Exam::Func()
{
    Exam::count++;
    cout << Exam::count;
}

int main()
{
    Exam obj;
    obj.Func();
    return 0;
}

// Kết quả: 6
// Giải thích: Trong hàm main, obj được khởi tạo và gọi hàm Func. Trong hàm Func, count được tăng lên 1 nên kết quả là 6.