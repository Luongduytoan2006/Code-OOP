#include <iostream>
using namespace std;

class Exam
{
    int prop_x, prop_y;

public:
    Exam(int = 0, int = 0);
    ~Exam();
    int getPropX() const;
    int getPropY();
};

Exam::Exam(int prop_x, int prop_y)
    : prop_x(prop_x), prop_y(prop_y)
{
}

Exam::~Exam()
{
}

int Exam::getPropX() const
{
    return this->prop_x;
}

int Exam::getPropY()
{
    return this->prop_y;
}

int main()
{
    const Exam obj;
    cout << obj.getPropX() << obj.getPropY();
    return 0;
}

// Kết quả: 00
// Giải thích: Trong hàm main, obj là một đối tượng hằng nên không thể thay đổi giá trị của nó. Khi gọi hàm getPropX và getPropY, prop_x và prop_y đều bằng 0 nên kết quả là 00.