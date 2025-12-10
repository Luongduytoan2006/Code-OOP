// CÂU 47
#include <iostream>
using namespace std;

class Base
{
};

class Derived : public Base // Derived kế thừa public từ Base
{
};

void Func()
{
    throw Derived(); // Ném ra một đối tượng kiểu Derived
}

int main()
{
    try
    {
        Func();
    }
    // Catch nhận tham chiếu hằng tới Base (const Base&).
    // Quy tắc C++: Catch kiểu lớp cha (Base) CÓ THỂ bắt được ngoại lệ kiểu lớp con (Derived).
    // Vì vậy, exception Derived ở trên sẽ lọt vào đây.
    catch (const Base&)
    {
        // Lưu ý: Code trong ảnh ghi "Caught a exception" (sai ngữ pháp tiếng Anh), 
        // nhưng về mặt logic code thì dòng này được thực thi.
        cerr << "Caught a exception"; 
    }
    return 0;
}

/**
A. Caught an exception -> ĐÚNG (Đáp án đã sửa lại ngữ pháp tiếng Anh cho đúng so với code gốc)
B. None of the mentioned
C. Both Caught an exception & NULL
D. NULL

Giải thích:
- Lớp `Derived` là con của `Base`.
- Trong khối `try`, chương trình ném ra ngoại lệ kiểu `Derived`.
- Khối `catch` được thiết kế để bắt `Base` (hoặc tham chiếu tới `Base`).
- Theo tính chất đa hình của C++, ngoại lệ lớp con hoàn toàn tương thích và bị bắt bởi `catch` của lớp cha.
- Kết quả là in ra dòng thông báo trong `catch`.
*/