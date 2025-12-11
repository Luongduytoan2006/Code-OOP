#include <iostream>
using namespace std;

class BaseA
{
protected:
    int x;

public:
    BaseA();
    void Show();
};

BaseA::BaseA()
{
    this->x = 5;
}

void BaseA::Show()
{
    cout << this->x;
}

class BaseB
{
protected:
    int x;

public:
    BaseB();
    void Show();
};

BaseB::BaseB()
{
    this->x = 10;
}

void BaseB::Show()
{
    cout << this->x;
}

class Derive : public BaseA, public BaseB
{
};

int main()
{
    Derive obj;
    obj.BaseA::Show();
    system("pause");
    return 0;
}

// Kết quả: 5
// Giải thích: Khi gọi hàm Show() của lớp cơ sở BaseA thông qua phạm vi giới hạn, giá trị của x của lớp cơ sở BaseA được hiển thị. Trong trường hợp này, giá trị của x của lớp cơ sở BaseA là 5. Do đó, kết quả là 5. Lưu ý rằng, khi một lớp dẫn xuất kế thừa từ nhiều lớp cơ sở, nó có thể chứa nhiều bản sao của các thành viên của lớp cơ sở. Để truy cập đến một thành viên cụ thể của một lớp cơ sở, phạm vi giới hạn có thể được sử dụng.