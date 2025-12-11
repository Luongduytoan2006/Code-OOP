#include <iostream>
using namespace std;

class Exam
{
    int prop;

public:
    Exam();
    Exam(double prop);
    ~Exam();
    bool operator<(const Exam &);
};

Exam::Exam()
{
}

Exam::Exam(double prop)
    : prop(prop)
{
}

Exam::~Exam()
{
}

bool Exam::operator<(const Exam &obj)
{
    /* Add code here */
}

int main()
{
    Exam obj_x(10);
    Exam obj_y = Exam(14);

    if (obj_x < obj_y)
        cout << "obj_y has large prop";
    else
        cout << "obj_x has large prop";

    return 0;
}

// Kết quả: obj_x has large prop
// Giải thích: Trong chương trình này, chúng ta định nghĩa một toán tử < để so sánh giá trị của thuộc tính prop của hai đối tượng của lớp Exam. Khi chúng ta so sánh giá trị của thuộc tính prop của hai đối tượng obj_x và obj_y, giá trị của thuộc tính prop của đối tượng obj_x sẽ được so sánh với giá trị của thuộc tính prop của đối tượng obj_y. Do giá trị của thuộc tính prop của đối tượng obj_x nhỏ hơn giá trị của thuộc tính prop của đối tượng obj_y, chuỗi "obj_x has large prop" sẽ được hiển thị. Do đó, kết quả là "obj_x has large prop".