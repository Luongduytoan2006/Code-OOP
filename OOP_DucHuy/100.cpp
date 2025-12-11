#include <iostream>
using namespace std;

class Exam
{
public:
    int prop;
    void Func();
};

void Exam::Func()
{
    cout << "ITF";
}

void (Exam::*pmfn)() = &Exam::Func;
int Exam::*pmd = &Exam::prop;

int main()
{
    Exam obj;
    Exam *ptr = new Exam;

    (obj.*pmfn)();
    (ptr->*pmfn)();
    obj.*pmd = 1;
    ptr->*pmd = 2;

    cout << obj.*pmd << ptr->*pmd;
    return 0;
}

// Kết quả: ITF12
// Giải thích: Trong chương trình này, chúng ta định nghĩa một phương thức Func() và một thành viên dữ liệu prop của lớp Exam. Chúng ta cũng định nghĩa một con trỏ hàm thành viên pmfn trỏ đến phương thức Func() và một con trỏ thành viên dữ liệu pmd trỏ đến thành viên dữ liệu prop. Trong hàm main(), chúng ta khởi tạo một đối tượng obj và một con trỏ ptr trỏ đến một đối tượng khác của lớp Exam. Chúng ta gọi phương thức Func() thông qua đối tượng obj và con trỏ ptr, sau đó gán giá trị 1 cho thành viên dữ liệu prop của đối tượng obj và giá trị 2 cho thành viên dữ liệu prop của đối tượng mà con trỏ ptr trỏ đến. Khi chúng ta in ra giá trị của thành viên dữ liệu prop thông qua đối tượng obj và con trỏ ptr, giá trị 12 sẽ được hiển thị. Do đó, kết quả là "ITF12".