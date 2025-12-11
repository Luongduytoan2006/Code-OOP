#include <iostream>
using namespace std;
class Exam
{
    int var1, var2;

public:
    Exam(int = 0, int = 0);
    ~Exam();
    static void Func1();
    static void Func2();
};
Exam::Exam(int var1, int var2)
{
    this->var1 = var1;
    this->var2 = var2;
}
Exam::~Exam()
{
}
void Exam::Func1()
{
    cout << "ITF";
}
void Exam::Func2()
{
    cout << "DUT";
    Exam::Func1();
}
int main()
{
    Exam obj;
    obj.Func2();
    return 0;
}

// Kết quả: DUTITF
// Giải thích: Trong chương trình này, chúng ta định nghĩa hai phương thức tĩnh Func1() và Func2() của lớp Exam. Khi chúng ta gọi phương thức Func2() thông qua một đối tượng obj của lớp Exam, nó sẽ in ra "DUT" và sau đó gọi phương thức Func1() thông qua lớp Exam. Do đó, kết quả là "DUTITF".