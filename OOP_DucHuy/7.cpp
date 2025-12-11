#include <iostream>
using namespace std;
class Base
{
public:
    virtual void show() = 0;
};
int main()
{
    Base b;
    Base *bp;
    system("pause");
    return 0;
}

// Kết quả: Compiler Error
// Giải thích: Lớp Base chứa một hàm ảo show() và được khai báo là lớp trừu tượng bằng cách đặt một hàm ảo bằng 0. Do đó, lớp Base trở thành lớp trừu tượng và không thể tạo đối tượng của nó. Khi cố gắng tạo một đối tượng của lớp Base, chương trình sẽ không biên dịch được và sẽ báo lỗi.