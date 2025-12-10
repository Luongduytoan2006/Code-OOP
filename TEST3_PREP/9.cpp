// CÂU 9
#include "iostream" // include bằng dấu " " vẫn hợp lệ
using namespace std;
class Base
{
    int x, y, z;
    public:
        Base()
        {
            x = y = z = 0;
        }
        // Constructor này có tham số mặc định: yy='A'(65), zz='B'(66)
        // Khi được gọi từ Derived: xx=65, yy=66, zz lấy mặc định là 66 ('B')
        Base(int xx, int yy = 'A', int zz = 'B')
        {
            x = xx;         // x = 65
            y = x + yy;     // y = 65 + 66 = 131
            z = x + y;      // z = 65 + 131 = 196
            // Lưu ý: x, y, z này là của Base, bị che bởi x, y của Derived
        }
        void Display()
        {
            cout << x << y << z;
        }
};
class Derived : public Base
{
    int x, y; // Biến x, y này che khuất x, y của Base
    public:
        // Constructor mặc định tham số: xx=65, yy=66
        Derived(int xx = 65, int yy = 66) : Base(xx, yy)
        {
            y = xx; // y (Derived) = 65
            x = yy; // x (Derived) = 66
        }
        void Display()
        {
            cout << x << y; // In x, y của Derived
        }
};
int main()
{
    Derived objD; // Gọi Derived(65, 66)
    objD.Display(); // Gọi Derived::Display -> in x(66) rồi in y(65) -> 6665
    system("pause");
    return 0;
}

/**
A. Compile Error
B. 6566
C. Another Answer
D. 6665 -> ĐÚNG
E. Runtime Error
F. 66 65 65 131 196

Giải thích:
1. Object `objD` được tạo, gọi `Derived(65, 66)`.
2. Trong constructor `Derived`: gán `y = 65`, `x = 66` (biến của lớp con).
3. Hàm `Display()` của `Derived` in ra `x` rồi `y` -> 6665.
*/