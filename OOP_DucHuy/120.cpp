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
    int var_i = 2;
    cout << obj.operator,(var_i);
    return 0;
}

// Kết quả: 2
// Giải thích: Trong hàm main, obj là một đối tượng của lớp Exam, var_i = 2. Khi gọi hàm obj.operator,(var_i) thì hàm operator, sẽ trả về giá trị của prop nên kết quả là 2.