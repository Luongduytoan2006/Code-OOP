#include <iostream>
using namespace std;

class X
{
public:
    X()
    {
        cout << "X";
    }
    ~X()
    {
        cout << "~X";
    }
};

class Y : public X
{
public:
    Y()
    {
        cout << "Y";
    }
    ~Y()
    {
        cout << "~Y";
    }
};

int main()
{
    Y obj;
    system("pause");
    return 0;
}

// Kết quả: XY~Y~X
// Giải thích: Trong chương trình này, lớp cơ sở X chứa một hàm tạo và một hàm hủy. Lớp dẫn xuất Y cũng chứa một hàm tạo và một hàm hủy. Khi tạo một đối tượng của lớp dẫn xuất Y, hàm tạo của lớp cơ sở X sẽ được gọi trước, sau đó hàm tạo của lớp dẫn xuất Y sẽ được gọi. Khi đối tượng kết thúc vòng đời của nó, hàm hủy của lớp dẫn xuất Y sẽ được gọi trước, sau đó hàm hủy của lớp cơ sở X sẽ được gọi. Do đó, kết quả là XY~Y~X.