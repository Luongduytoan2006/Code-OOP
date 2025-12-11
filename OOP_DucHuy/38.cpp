#include <iostream>
using namespace std;

class Base
{
    int _x;

public:
    Base(int x) : _x(x)
    {
        cout << "A";
    }
};

class Child : public Base
{
    int _y;

public:
    Child(int x, int y) : Base(x), _y(y)
    {
        cout << "B";
    }
};

int main()
{
    Child c1(1, 2);
    system("pause");
    return 0;
}

// Kết quả: AB
// Giải thích: Trong chương trình này, lớp cơ sở Base chứa một hàm tạo có tham số. Lớp dẫn xuất Child cũng chứa một hàm tạo có tham số. Khi tạo một đối tượng của lớp dẫn xuất Child, hàm tạo của lớp cơ sở Base sẽ được gọi trước, sau đó hàm tạo của lớp dẫn xuất Child sẽ được gọi. Do đó, kết quả là AB.