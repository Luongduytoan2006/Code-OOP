#include <iostream>
using namespace std;

class Exam
{
public:
    void Func1();
    void Func2();
};

void Exam::Func1()
{
}

void Exam::Func2()
{
}

int main()
{
    Exam obj;
    cout << sizeof(obj);
    return 0;
}

// Kết quả: 1
// Giải thích: Trong chương trình này, chúng ta định nghĩa một lớp Exam không có thành viên dữ liệu. Khi chúng ta in ra kích thước của một đối tượng obj của lớp Exam, kích thước của đối tượng này sẽ là 1 byte. Điều này là do mỗi đối tượng trong C++ phải có kích thước tối thiểu là 1 byte.