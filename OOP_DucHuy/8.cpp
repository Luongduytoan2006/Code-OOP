#include <iostream>
using namespace std;
class base
{
    int arr[10];
};
class b1 : public base
{
};
class b2 : public base
{
};
class derived : public b1, public b2
{
};
int main()
{
    cout << sizeof(derived);
    system("pause");
    return 0;
}

// Kết quả: 80
// Giải thích: Kích thước của một đối tượng được xác định bởi tổng kích thước của các thành phần của nó. Trong trường hợp này, lớp base chứa một mảng 10 phần tử kiểu int, có kích thước 10 * 4 = 40 byte. Lớp b1 và lớp b2 kế thừa lớp base và không chứa bất kỳ thành viên nào. Do đó, kích thước của lớp b1 và lớp b2 là 40 byte. Lớp derived kế thừa lớp b1 và lớp b2, do đó nó chứa hai bản sao của lớp base, mỗi bản sao có kích thước 40 byte. Do đó, kích thước của lớp derived là 40 + 40 = 80 byte.