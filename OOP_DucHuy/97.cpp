#include <iostream>
using namespace std;

class Exam
{
    int var1, var2, var3;

public:
    Exam(int = 1, int = 3, int = 0);
    ~Exam();
    void Func();
};

Exam::Exam(int var1, int var2, int var3)
{
    this->var1 = var1;
    this->var2 = var2;
    this->var3 = var3;
    this->Func();
}

Exam::~Exam()
{
}

void Exam::Func()
{
    cout << this->var1 << this->var2 << this->var3;
}

int main()
{
    int var1 = 0, var2 = 1, var3 = 2;
    int &ref1 = ++var1;
    int &ref2 = --var2;
    int var4 = var3 + var2 - var3;
    Exam obj(ref1, ref2, var4);
    return 0;
}

// Kết quả: 011
// Giải thích: Trong chương trình này, chúng ta định nghĩa một lớp Exam với ba thuộc tính var1, var2 và var3. Chúng ta cũng định nghĩa một phương thức Func() để in ra giá trị của các thuộc tính của đối tượng. Trong hàm main(), chúng ta khởi tạo ba biến var1, var2 và var3 với giá trị lần lượt là 0, 1 và 2. Chúng ta cũng khởi tạo hai tham chiếu ref1 và ref2 trỏ đến var1 và var2. Sau đó, chúng ta khởi tạo biến var4 với giá trị là var3 + var2 - var3 = 1. Cuối cùng, chúng ta khởi tạo một đối tượng obj với các tham số là ref1, ref2 và var4. Khi chúng ta gọi phương thức Func() của đối tượng obj, giá trị của các thuộc tính var1, var2 và var3 sẽ được in ra. Do đó, kết quả là "011".