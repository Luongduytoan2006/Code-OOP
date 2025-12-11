#include <iostream>
using namespace std;

class One
{
public:
    double add(double x)
    {
        return x + 0.1;
    }
};

class Two : public One
{
public:
    using One::add;
    int add(int x)
    {
        return x + 1;
    }
};

int main()
{
    Two obj;
    cout << obj.add(10) << obj.add(10.5);
    system("pause");
    return 0;
}

// Kết quả: 1110.6
// Giải thích: Trong chương trình này, lớp cơ sở One chứa một phương thức add() để thêm 0.1 vào một số thực. Lớp dẫn xuất Two cung cấp một triển khai cho phương thức add() để thêm 1 vào một số nguyên. Khi gọi phương thức add() trên một đối tượng của lớp dẫn xuất Two với một số nguyên và một số thực, phương thức add() của lớp dẫn xuất Two sẽ được gọi để thêm 1 vào số nguyên và phương thức add() của lớp cơ sở One sẽ được gọi để thêm 0.1 vào số thực. Do đó, kết quả là 1110.6.