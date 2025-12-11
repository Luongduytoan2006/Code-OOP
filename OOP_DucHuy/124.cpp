#include <iostream>
using namespace std;

class Exam
{
    int prop_x, prop_y;

public:
    void setProp();
    friend double Func(const Exam &);
};

void Exam::setProp()
{
    this->prop_x = 100;
    this->prop_y = 200;
}

double Func(const Exam &obj)
{
    return float(obj.prop_x + obj.prop_y) / 2;
}

int main()
{
    Exam obj;
    obj.setProp();
    cout << Func(obj);
    return 0;
}

// Kết quả: 150
// Giải thích: Trong hàm main, obj được khởi tạo và gọi hàm setProp. Trong hàm setProp, prop_x = 100, prop_y = 200. Khi gọi hàm Func, hàm trả về giá trị trung bình của prop_x và prop_y nên kết quả là 150.