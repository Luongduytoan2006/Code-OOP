#include <iostream>
using namespace std;

class Base
{
    int size;
    float *ptr;

public:
    Base(int = 2, int = 3);
};

Base::Base(int size, int n) : size(size)
{
    this->ptr = new float[this->size];
    for (int i = 0; i < this->size; i++)
        #### #;
}

int main()
{
    Base obj;
    system("pause");
    return 0;
}

// Kết quả: Lỗi biên dịch
// Giải thích: Trong hàm dựng của lớp Base, chúng ta cần cấp phát bộ nhớ động cho con trỏ ptr nhưng chưa cấp phát. Do đó, chương trình sẽ báo lỗi biên dịch.