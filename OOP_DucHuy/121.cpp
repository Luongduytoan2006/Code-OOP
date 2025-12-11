#include <iostream>
using namespace std;

class Base
{
    int x;

public:
    Base(int = 0);
    ~Base();
};

Base::Base(int x)
{
    this->x = x;
}

Base::~Base()
{
    cout << this->x;
}

void Func(const Base &obj)
{
    Base *ptr = new Base(3);
    delete ptr;
}

int main()
{
    Base obj(4);
    Func(obj);
    system("pause");
    return 0;
}

// Kết quả: 43
// Giải thích: Trong hàm main, obj.x = 4. Khi gọi hàm Func, obj được truyền vào hàm dưới dạng tham chiếu nên không gọi hàm sao chép. Trong hàm Func, ptr được cấp phát bộ nhớ động và giải phóng nên kết quả là 43.