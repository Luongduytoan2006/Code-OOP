#include <iostream>
using namespace std;
template <typename T>
void Func(T var_x)
{
    int count = 3;
    T arr[count];
    for (int i = 0; i < count; i++)
    {
        arr[i] = var_x++;
        cout << arr[i];
    }
};
int main()
{
    double var_x = 2.1;
    Func(var_x);
    return 0;
}

// Kết quả: 2.13.14.1
// Giải thích: Trong hàm Func(), một mảng arr được khai báo với kích thước count = 3. Sau đó, một vòng lặp được sử dụng để gán giá trị var_x cho các phần tử của mảng arr. Trong trường hợp này, giá trị của var_x là 2.1. Do đó, giá trị của các phần tử của mảng arr là 2.1, 3.1 và 4.1. Khi hiển thị các phần tử của mảng arr, kết quả là 2.13.14.