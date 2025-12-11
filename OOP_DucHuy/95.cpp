#include <iostream>
using namespace std;

class Exam
{
    int prop;

public:
    Exam(int = 1);
    Exam(const Exam &);
    ~Exam();
    const Exam &operator=(const Exam &);
};

Exam::Exam(int prop)
    : prop(prop)
{
    cout << "1";
}

Exam::Exam(Exam const &obj)
    : prop(obj.prop)
{
    cout << "2";
}

Exam::~Exam()
{
}

const Exam &Exam::operator=(Exam const &obj)
{
    if (this != &obj)
    {
        this->prop = obj.prop;
        cout << "3";
    }
    return *this;
}

Exam Func()
{
    Exam obj;
    return obj;
}

int main()
{
    Exam obj;
    obj = Func();
    return 0;
}

// Kết quả: 13
// Giải thích: Trong chương trình này, chúng ta định nghĩa một hàm toán tử gán = để gán giá trị của một đối tượng của lớp Exam cho một đối tượng khác. Khi chúng ta gọi hàm Func() để trả về một đối tượng của lớp Exam, hàm này sẽ tạo một đối tượng tạm thời và trả về nó. Sau đó, hàm toán tử gán = sẽ được gọi để gán giá trị của đối tượng tạm thời này cho đối tượng obj. Do đó, kết quả là "13".