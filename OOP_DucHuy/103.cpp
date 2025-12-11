#include <iostream>
using namespace std;

class Exam
{
    int var;

public:
    Exam(int);
    void Func();
    ~Exam();
};

Exam::Exam(int var)
{
    this->var = var;
}

void Exam::Func()
{
    cout << this->var;
}

Exam::~Exam()
{
}

int main()
{
    Exam arr[5];
    for (int i = 0; i < 5; i++)
        arr[i].Func();

    return 0;
}

// Kết quả: Compiler error
// Giải thích: Trong chương trình này, chúng ta cố gắng khởi tạo một mảng của lớp Exam mà không có hàm khởi tạo mặc định. Điều này sẽ dẫn đến lỗi biên dịch vì mảng yêu cầu các phần tử của nó phải được khởi tạo. Để sửa lỗi này, chúng ta cần cung cấp một hàm khởi tạo mặc định cho lớp Exam.