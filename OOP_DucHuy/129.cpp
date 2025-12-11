#include <iostream>
#include <string>
using namespace std;

class Exam
{
    int prop;

public:
    Exam(int);
    ~Exam();
    void setProp(int);
    int getProp();
};

Exam::Exam(int prop)
    : prop(prop)
{
}

Exam::~Exam()
{
}

void Exam::setProp(int prop)
{
    this->prop = prop;
}

int Exam::getProp()
{
    return prop;
}

int main()
{
    Exam obj;
    obj.setProp(5);
    cout << obj.getProp();
    return 0;
}

// Kết quả: Lỗi biên dịch
// Giải thích: Trong hàm main, obj được khởi tạo nhưng không truyền tham số vào hàm dựng nên sẽ báo lỗi biên dịch.
