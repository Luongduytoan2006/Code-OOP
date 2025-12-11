#include <iostream>
using namespace std;

int main()
{
    struct Exam
    {
        int var;
    };

    Exam *ptr = new Exam;
    (*ptr).var = 1;
    cout << (*ptr).var;
    return 0;
}

// Kết quả: 1
// Giải thích: Trong chương trình này, chúng ta định nghĩa một cấu trúc Exam với một thành viên dữ liệu var. Chúng ta cấp phát bộ nhớ động cho một con trỏ ptr trỏ đến một đối tượng của cấu trúc Exam và sau đó gán giá trị 1 cho thành viên dữ liệu var của đối tượng đó. Khi chúng ta in ra giá trị của thành viên dữ liệu var thông qua con trỏ ptr, giá trị 1 sẽ được hiển thị. Do đó, kết quả là 1.