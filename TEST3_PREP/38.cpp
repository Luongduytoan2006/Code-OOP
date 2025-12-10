// CÂU 38
#include <iostream>
using namespace std;

void Func(int var_x)
{
    int var_y = 1;
    while (true)
    {
        // var_x được truyền vào là 2.
        // Vòng 1: var_y = 1. 1 >= 2 (Sai) -> Bỏ qua if.
        // Vòng 2: var_y = 2. 2 >= 2 (Đúng) -> Thực hiện throw 2.
        if (var_y >= var_x)
            throw var_y; // Ném ngoại lệ giá trị 2, thoát khỏi hàm ngay lập tức.

        cout << var_y; // Vòng 1: In ra "1".
        var_y++;       // Vòng 1: var_y tăng lên 2.
    }
}

int main()
{
    try
    {
        Func(2);
    }
    catch (int e) // Bắt được ngoại lệ kiểu int (giá trị 2)
    {
        cout << "exception:" << e; // In ra "exception:2"
    }
    return 0;
}

/**
A. Another Answer
B. exception:2
C. Runtime Error
D. 1
E. Compile Error
F. 1exception:2 -> ĐÚNG

Giải thích:
- Vòng lặp đầu tiên: var_y = 1, in ra "1". Tăng var_y lên 2.
- Vòng lặp thứ hai: var_y = 2, điều kiện (2 >= 2) đúng -> ném ngoại lệ giá trị 2.
- Hàm dừng, nhảy sang catch.
- Catch in ra "exception:2".
- Kết quả nối chuỗi: 1exception:2
*/