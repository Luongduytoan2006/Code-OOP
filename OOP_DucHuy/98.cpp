#include <iostream>
using namespace std;

ostream &operator<<(ostream &o, int var_x)
{
    return o;
}

int main()
{
    cout << 5;
    cin.get();
    return 0;
}

// Kết quả: 5
// Giải thích: Trong chương trình này, chúng ta định nghĩa một hàm toán tử << để hiển thị giá trị của một biến kiểu int. Khi chúng ta sử dụng toán tử << để hiển thị giá trị của biến var_x, giá trị của biến này sẽ được hiển thị. Do đó, kết quả là 5.