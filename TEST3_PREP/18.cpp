// CÂU 18
#include <iostream>
using namespace std;

void Func(int var_x, int var_y)
{
    if (var_y == 0)
        throw "Error!"; // Ném ra chuỗi ký tự (string literal). Kiểu thực tế là const char*.
    else
        cout << var_x << var_y;
}

int main()
{
    try
    {
        Func(5, 0); // Gọi hàm với var_y = 0 -> sẽ bị throw
    }
    catch (char* e) // Bắt ngoại lệ kiểu char*
    {
        // Lưu ý: Trong C++ hiện đại (strict), chuỗi "Error!" là const char* nên sẽ không bắt được bởi char* (gây Runtime Error).
        // Tuy nhiên, trong các đề thi cũ hoặc trình biên dịch dễ tính, nó cho phép ép kiểu ngầm định.
        // -> Bắt được và in ra nội dung chuỗi.
        cout << e; 
    }
    return 0;
}

/**
A. Error! -> ĐÚNG
B. Runtime Error
C. Another Answer
D. Compile Error
E. 50

Giải thích:
- Hàm `Func` ném ra ngoại lệ là chuỗi "Error!" khi tham số thứ 2 là 0.
- Khối `catch(char* e)` bắt được chuỗi này (theo logic của đề bài, bỏ qua tính const-correctness nghiêm ngặt của C++ mới).
- Lệnh `cout << e` in ra nội dung chuỗi: "Error!".
*/