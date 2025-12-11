#include <iostream>
using namespace std;

class Exam
{
    int prop_x, prop_y;

public:
    Exam();
    Exam(int, int);
    Exam operator()(int, int, int);
    friend ostream &operator<<(ostream &, const Exam &);
};

Exam::Exam()
{
    this->prop_x = this->prop_y = 0;
}

Exam::Exam(int prop_x, int prop_y)
    : prop_x(prop_x), prop_y(prop_y)
{
}

Exam Exam::operator()(int prop_x, int prop_y, int var_x)
{
    return Exam(prop_x + var_x + 10, prop_y + var_x + 100);
}

ostream &operator<<(ostream &o, const Exam &obj)
{
    o << obj.prop_x << obj.prop_y;
    return o;
}

int main()
{
    Exam obj_x(11, 10), obj_y;
    cout << obj_x;
    obj_y = obj_x(10, 10, 10);
    cout << obj_y;
    return 0;
}

// Kết quả: 1110100
// Giải thích: Trong hàm main, obj_x được khởi tạo với prop_x = 11, prop_y = 10. Khi gọi hàm obj_x(10, 10, 10), prop_x = 10 + 10 + 10 = 30, prop_y = 10 + 10 + 100 = 120. Do đó kết quả là 1110100.
