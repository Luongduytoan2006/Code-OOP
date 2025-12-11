#include <iostream>
using namespace std;
class Exam
{
    int prop;
    Exam();

public:
    void setProp(int);
    int getProp();
};

Exam::Exam()
    : prop(5)
{
}

void Exam::setProp(int prop)
{
    this->prop = prop;
}

int Exam::getProp()
{
    return this->prop;
}

int main()
{
    Exam obj;
    obj.setProp(10);
    cout << obj.getProp();
    return 0;
}

// Kết quả: 10
// Giải thích: Trong chương trình này, chúng ta định nghĩa một phương thức setProp() để thiết lập giá trị của thuộc tính prop của một đối tượng của lớp Exam và một phương thức getProp() để trả về giá trị của thuộc tính prop của đối tượng đó. Khi chúng ta gọi phương thức setProp() để thiết lập giá trị của thuộc tính prop của đối tượng obj là 10 và sau đó gọi phương thức getProp() để trả về giá trị của thuộc tính prop của đối tượng obj, giá trị 10 sẽ được trả về. Do đó, kết quả là 10.