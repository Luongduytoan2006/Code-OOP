// CÂU 19
#include <iostream>
using namespace std;

template <class T, int max> // Template với tham số kiểu T và tham số giá trị max
int Func(T arr[], int var_x)
{
    int var_y = max; // Khởi tạo giá trị min tạm thời bằng max
    for (int i = 0; i < var_x; i++)
        if (arr[i] < var_y) // Tìm phần tử nhỏ nhất trong mảng
            var_y = arr[i];
    return var_y; // Trả về giá trị nhỏ nhất tìm được
}

int main()
{
    int arr_x[] = { 10, 20, 15, 12 };
    int var_x = sizeof(arr_x) / sizeof(arr_x[0]); // var_x = 4

    char arr_y[] = { 1, 2, 3 }; // Mảng char chứa giá trị số nguyên 1, 2, 3
    int var_y = sizeof(arr_y) / sizeof(arr_y[0]); // var_y = 3

    // Func 1: Tìm min của {10, 20, 15, 12} với giá trị khởi tạo 10000 -> Kết quả: 10
    // Func 2: Tìm min của {1, 2, 3} với giá trị khởi tạo 256 -> Kết quả: 1
    // cout in nối tiếp 2 kết quả: "10" và "1"
    cout << Func<int, 10000>(arr_x, var_x) << Func<char, 256>(arr_y, var_y);
    
    return 0;
}

/**
A. 101 -> ĐÚNG
B. Compile Error
C. 10000256
D. Runtime Error
E. 122
F. Another Answer

Giải thích:
- Hàm `Func` thực chất là hàm tìm giá trị nhỏ nhất (Min) trong mảng.
- Lần gọi 1: Min({10, 20, 15, 12}) -> Trả về 10.
- Lần gọi 2: Min({1, 2, 3}) -> Trả về 1.
- Toán tử `<<` in liền nhau nên màn hình hiển thị: 101.
*/