#include <iostream>
using namespace std;

class Base
{
    double x;

public:
    Base(double = 0.0);
    Base(double);
    operator double();
    operator int();
};

Base::Base(double x) : x(x)
{
}

Base::operator double()
{
    return this->x;
}

Base::operator int()
{
    return int(this->x);
}

int main()
{
    Base obj1(9.7), obj2(2.6);
    double x = obj1.operator double();
    int y = obj2.operator int();
    cout << x << y;
    system("pause");
    return 0;
}

#include <iostream>
using namespace std;

class Exam
{
    int prop_x, prop_y;

public:
    Exam();
    Exam(int, int);
    ~Exam();
    Exam operator+(const Exam &);
    friend ostream &operator<<(ostream &, const Exam &);
};

Exam::Exam()
{
}

Exam::Exam(int prop_x, int prop_y)
    : prop_x(prop_x), prop_y(prop_y)
{
}

Exam::~Exam()
{
}

Exam Exam::operator+(const Exam &obj)
{
    return Exam(this->prop_x + obj.prop_x, this->prop_y + obj.prop_y);
}

ostream &operator<<(ostream &o, const Exam &obj)
{
    o << obj.prop_x << obj.prop_y;
    return o;
}

int main()
{
    Exam obj_x(4, 1);
    Exam obj_y(3, 2);
    Exam obj_z = obj_x + obj_y;
    cout << obj_z;
    return 0;
}

// Kết quả: 73
// Giải thích: Trong hàm main, obj_x = (4, 1), obj_y = (3, 2). Khi gọi hàm operator+, obj_z = obj_x + obj_y = (4 + 3, 1 + 2) = (7, 3). Khi gọi hàm operator<<, prop_x = 7, prop_y = 3 nên kết quả là 73.