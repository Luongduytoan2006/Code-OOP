#include <iostream>
using namespace std;

struct Struct
{
    class Base
    {
    public:
        void Show(int x, float y = 97.50, char z = 'a')
        {
            cout << x << y << z;
        }
    } obj2;
} obj1;

int main()
{
    obj1.obj2.Show(12, 'b');
    system("pause");
    return 0;
}

// Kết quả: 12.097.5b
// Giải thích: Trong hàm main, khi gọi hàm Show, tham số thứ 2 và thứ 3 được gán giá trị mặc định nên kết quả là 12.097.5b.
