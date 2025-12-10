// CÂU 17
#include <iostream>
using namespace std;
int main()
{
    try
    {
        throw 1; // Ném ra số nguyên 1
    }
    catch (int& e) // Bắt exception kiểu int
    {
        cout << "exception number " << e; // In: exception number 1
        return 0; // Kết thúc chương trình ngay lập tức
    }
    
    // Dòng này không bao giờ được thực thi vì đã return trong catch
    cout << "No exception";
    return 0;
}

/**
A. Another Answer
B. Compile Error
C. exception number 1 -> ĐÚNG
D. Runtime Error
E. exception number
F. No exception

Giải thích:
- Khối try ném ra giá trị 1 (int).
- Khối catch bắt được (int& e), in ra chuỗi và giá trị e (1).
- Lệnh return 0 trong catch kết thúc hàm main luôn, nên dòng "No exception" bên dưới không chạy.
*/