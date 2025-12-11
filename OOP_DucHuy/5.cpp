#include <iostream>
using namespace std;
class P
{
public:
    virtual void show() = 0;
};
class Q : public P
{
    int x;
};
int main()
{
    Q q;
    system("pause");
    return 0;
}

// Kết quả: Compiler Error
// Giải thích: Lớp Q kế thừa lớp P và ghi đè hàm ảo show() của lớp P. Tuy nhiên, lớp Q không cung cấp một định nghĩa cho hàm ảo show(). Do đó, lớp Q trở thành lớp trừu tượng và không thể tạo đối tượng của nó. Khi cố gắng tạo một đối tượng của lớp Q, chương trình sẽ không biên dịch được và sẽ báo lỗi.