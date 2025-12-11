#include <iostream>
using namespace std;

int Func(int, int);
int Func(int, int, int = 15);

int main()
{
    cout << Func(2, 4);
    system("pause");
    return 0;
}

int Func(int x, int y)
{
    return x * y;
}

int Func(int x, int y, int z)
{
    return x * y * z;
}

// Kết quả: 8
// Giải thích: Trong hàm main, khi gọi hàm Func(2, 4) thì sẽ gọi hàm có 2 tham số. Do đó kết quả là 8.