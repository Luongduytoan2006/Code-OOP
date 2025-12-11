#include <iostream>
using namespace std;
template <typename T = double, int count = 3>
T Func(T var_x)
{
    for (int i = 0; i < count; ++i)
    {
        var_x = var_x * var_x;
    }
    return var_x;
}
int main()
{
    double var_x = 2.1;
    cout << var_x << Func<>(var_x);
    return 0;
}

// Kết quả: 2.1378.229
// Giải thích: Trong hàm Func(), giá trị của var_x được nhân với chính nó count lần. Trong trường hợp này, giá trị của var_x là 2.1 và count là 3. Do đó, giá trị của var_x sau khi thực hiện hàm Func() là 2.1 * 2.1 * 2.1 * 2.1 = 8.229. Khi hiển thị giá trị của var_x và giá trị trả về từ hàm Func(), kết quả là 2.1378.229.