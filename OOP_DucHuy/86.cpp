#include <iostream>
using namespace std;
class Exam
{
    int prop;

public:
    Exam(int = 1);
    int operator,(int);
};
Exam::Exam(int prop)
    : prop(prop)
{
}
int Exam::operator,(int prop)
{
    return prop;
}
int main()
{
    Exam obj;
    int var_1 = 2;
    cout << obj.operator,(var_1);
    return 0;
}

// Kết quả: 2
// Giải thích: Trong chương trình này, chúng ta định nghĩa một toán tử , để trả về giá trị của một đối tượng của lớp Exam. Khi chúng ta sử dụng toán tử , để trả về giá trị của đối tượng obj, giá trị của thuộc tính prop của đối tượng obj sẽ được trả về. Do đó, kết quả là 2.