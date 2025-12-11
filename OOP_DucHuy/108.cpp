#include <iostream>
using namespace std;
class Exam
{
    static int count;

public:
    ~Exam()
    {
        Exam::count--;
    }
    void Func();
    void operator()();
};

int Exam::count = 0;
Exam::~Exam()
{
    Exam::count--;
}
void Exam::Func()
{
    Exam::count++;
}
void Exam::operator()()
{
    cout << Exam::count;
}

int main()
{
    Exam obj_x, obj_y;
    obj_y.Func();
    obj_x.operator()();
    return 0;
}

// Kết quả: 2
// Giải thích: Trong chương trình này, chúng ta định nghĩa một phương thức tĩnh Func() để tăng giá trị của biến tĩnh count mỗi khi một đối tượng của lớp Exam được tạo. Khi chúng ta tạo hai đối tượng obj_x và obj_y, giá trị của biến count sẽ tăng lên 2. Sau đó, khi chúng ta gọi toán tử () để hiển thị giá trị của biến count, giá trị 2 sẽ được hiển thị. Do đó, kết quả là 2.