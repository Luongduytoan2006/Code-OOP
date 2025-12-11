#include <iostream>
using namespace std;

class Exam
{
public:
    Exam();
    ~Exam();
    static void Func();
};

Exam::Exam()
{
}

Exam::~Exam()
{
}

void Exam::Func()
{
    cout << "DUT";
}

int main()
{
    Exam::Func();
    return 0;
}

// Kết quả: DUT
// Giải thích: Trong chương trình này, chúng ta định nghĩa một phương thức tĩnh Func() của lớp Exam. Khi chúng ta gọi phương thức Func() thông qua lớp Exam, nó sẽ in ra "DUT". Do đó, kết quả là "DUT".