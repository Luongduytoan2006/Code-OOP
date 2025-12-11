#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Base()";
    }
    Base(int x)
    {
        cout << "Base(int x)";
    }
    ~Base()
    {
        cout << "~Base()";
    }
};

class Child : public Base
{
public:
    Child() : Base()
    {
        cout << "Child()";
    }
    Child(int x) : Base(x)
    {
        cout << "Child(int x)";
    }
    ~Child()
    {
        cout << "~Child()";
    }
};

int main()
{
    Child();
    Child(1);
    system("pause");
    return 0;
}

// Kết quả: Base()Child()Base(int x)Child(int x)~Child()~Base()~Child()~Base()

// Giải thích: Trong chương trình này, lớp cơ sở Base chứa một hàm tạo không có tham số và một hàm tạo có tham số. Lớp dẫn xuất Child cũng chứa một hàm tạo không có tham số và một hàm tạo có tham số. Khi tạo một đối tượng của lớp dẫn xuất Child không có tham số, hàm tạo của lớp cơ sở Base không có tham số sẽ được gọi trước, sau đó hàm tạo của lớp dẫn xuất Child không có tham số sẽ được gọi. Khi tạo một đối tượng của lớp dẫn xuất Child có tham số, hàm tạo của lớp cơ sở Base có tham số sẽ được gọi trước, sau đó hàm tạo của lớp dẫn xuất Child có tham số sẽ được gọi. Khi đối tượng kết thúc vòng đời của nó, hàm hủy của lớp dẫn xuất Child sẽ được gọi trước, sau đó hàm hủy của lớp cơ sở Base sẽ được gọi. Do đó, kết quả là Base()Child()Base(int x)Child(int x)~Child()~Base()~Child()~Base().