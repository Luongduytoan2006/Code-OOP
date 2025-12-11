#include <iostream>
using namespace std;

class A
{
public:
    virtual void fun();
};

class B
{
public:
    void fun();
};

int main()
{
    int a = sizeof(A), b = sizeof(B);
    if (a == b)
        cout << "a == b";
    else if (a > b)
        cout << "a > b";
    else
        cout << "a < b";
    system("pause");
    return 0;
}

// Kết quả: a > b
// Giải thích: Lớp A chứa một hàm ảo fun(). Khi sử dụng toán tử sizeof để tính kích thước của lớp A, kích thước của lớp A sẽ bằng kích thước của một con trỏ hàm vì lớp A chứa một hàm ảo. Lớp B không chứa hàm ảo, do đó kích thước của lớp B sẽ bằng kích thước của một đối tượng của lớp B. Do đó, kích thước của lớp A sẽ lớn hơn kích thước của lớp B.