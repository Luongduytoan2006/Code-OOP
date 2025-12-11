#include <iostream>
using namespace std;

static int Result;

class India
{
public:
    void Change(int x = 10, int y = 20, int z = 30)
    {
        cout << x + y + z;
    }

    void Display(int x = 40, float y = 50.00)
    {
        Result = x % x;
        cout << Result;
    }
};

class Bix
{
    int x, y;

public:
    void Change(int x, int y = 50)
    {
        cout << x + y;
    }
};

class IndiaBix : public India, public Bix
{
public:
    void Display(int x = 10, int xx = 100, int xxx = 1000)
    {
        Result = x + xx % x * x;
        cout << Result;
    }
};

int main()
{
    IndiaBix objBix;
    objBix.India::Display(10, 20.00);
    system("pause");
    return 0;
}

// Kết quả: 0
// Giải thích: Khi gọi hàm Display() của lớp dẫn xuất IndiaBix, tham số truyền vào là 10 và 20.00. Trong hàm Display() của lớp dẫn xuất IndiaBix, giá trị của x và xx được sử dụng để tính toán giá trị của Result. Do đó, giá trị của Result là 10 + 20 % 10 * 10 = 10 + 2 * 10 = 30. Sau đó, giá trị của Result được hiển thị, kết quả là 0. Lưu ý rằng, hàm Display() của lớp cơ sở India không được gọi trong trường hợp này.