// CÂU 36
#include <iostream>
using namespace std;

class Test1
{
    int x; // kích thước int = 4 bytes
    public:
        void show(); // Hàm thường: Không chiếm bộ nhớ trong đối tượng (lưu ở Code Segment)
};
void Test1::show() { }

class Test2
{
    int x; // 4 bytes
    public:
        // Hàm ảo (virtual): Để quản lý đa hình, trình biên dịch chèn thêm một con trỏ vptr (virtual pointer) vào đối tượng.
        // Trên hệ thống 32-bit (thường gặp trong đề thi), con trỏ kích thước 4 bytes.
        // Tổng size = sizeof(int) + sizeof(vptr) = 4 + 4 = 8 bytes.
        virtual void show(); 
};
void Test2::show() { }

int main()
{
    // sizeof(Test1) = 4
    // sizeof(Test2) = 8
    // In liền nhau: 48
    cout << sizeof(Test1) << sizeof(Test2);
    system("pause");
    return 0;
}

/**
A. Compile Error
B. Runtime Error
C. 44
D. 88
E. Another Answer
F. 48 -> ĐÚNG

Giải thích chi tiết:
1. Class `Test1`: Chỉ có 1 biến `int` -> Size là 4.
2. Class `Test2`: Có từ khóa `virtual`. Trình biên dịch sẽ thêm một con trỏ ảo (**vptr**) trỏ đến bảng phương thức ảo (**vtable**).
   - Kích thước `int` = 4.
   - Kích thước con trỏ (trên hệ 32-bit) = 4.
   - Tổng = 8.
3. Kết quả in ra là ghép của 4 và 8 -> 48.
(Lưu ý: Nếu chạy trên máy 64-bit, con trỏ là 8 bytes + padding -> size Test2 có thể là 16, nhưng trong các đáp án này chỉ có 48 là hợp lý với kiến trúc 32-bit).
*/