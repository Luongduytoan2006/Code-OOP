#include <iostream>
using namespace std;
int main()
{
    int var_x = 13, var_y = 60;
    var_x ^= var_y;
    var_y ^= var_x;
    var_x ^= var_y;
    cout << (var_x) << (var_y);
    return 0;
}

// Kết quả: 6013
// Giải thích: Trong chương trình này, chúng ta sử dụng toán tử XOR (^) để hoán đổi giá trị của hai biến var_x và var_y. Khi chúng ta hoán đổi giá trị của hai biến này, giá trị của var_x sẽ là 60 và giá trị của var_y sẽ là 13. Do đó, kết quả là 6013.