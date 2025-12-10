// CÂU 31
#include <iostream>
using namespace std;

double Func(int var_x, int var_y)
{
    if (var_y == 0)
    {
        throw "Error!"; // Ném ra ngoại lệ là chuỗi ký tự (const char*)
    }
    return (var_x / var_y);
}

int main()
{
    int var_x = 50;
    int var_y = 0;
    double var_z = 0;
    try
    {
        // Gọi hàm Func với var_y = 0.
        // Hàm sẽ ném ngoại lệ (throw) ngay lập tức.
        var_z = Func(var_x, var_y);
        
        // Dòng này bị bỏ qua do luồng chương trình đã nhảy sang block catch
        cout << var_z;
    }
    catch (const char* e) // Bắt đúng kiểu const char* của chuỗi "Error!"
    {
        cout << e; // In ra nội dung chuỗi lỗi
    }
    return 0;
}

/**
A. Compile Error
B. Error! -> ĐÚNG
C. 50
D. Runtime Error
E. 0
F. Another Answer

Giải thích:
- Khi `var_y = 0`, hàm `Func` ném ra chuỗi `"Error!"`.
- Khối `catch(const char* e)` bắt được ngoại lệ này.
- Lệnh `cout << e` in ra màn hình chuỗi `"Error!"`.
*/