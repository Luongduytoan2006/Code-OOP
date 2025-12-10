// CÂU 12
#include <iostream>
using namespace std;
int main()
{
    char* ptr;
    try
    {
        // Cấp phát động mảng 1024 ký tự.
        // Trong C++ chuẩn, nếu thất bại sẽ ném bad_alloc, hiếm khi trả về 0 (trừ khi dùng nothrow).
        // Giả sử cấp phát thành công.
        ptr = new char[1024]; 
        
        if (ptr == 0) // Điều kiện này False
            throw "Error !";
        else
            // In ra kích thước của BIẾN CON TRỎ (ptr), KHÔNG PHẢI kích thước mảng (1024).
            // Trên hệ thống 32-bit: pointer = 4 bytes.
            // Trên hệ thống 64-bit: pointer = 8 bytes.
            cout << sizeof(ptr); 
    }
    catch (char* e) // Bắt exception nếu có lỗi ném ra chuỗi char*
    {
        cout << e;
    }
    return 0;
}

/**
A. Another Answer
B. Compile Error
C. Error !
D. Runtime Error
E. Depends on the size of the data type
F. 4 -> ĐÚNG (Giả định hệ thống 32-bit thường dùng trong đề thi)
G. 8

Giải thích:
- Chương trình chạy bình thường (Happy path).
- Toán tử sizeof(ptr) trả về kích thước của biến con trỏ.
- Trong các bài test học thuật tiêu chuẩn (đặc biệt là các đề cũ hoặc giáo trình cơ sở), thường mặc định môi trường là 32-bit => Kết quả là 4 bytes.
- (Lưu ý: Nếu chạy trên máy tính hiện đại 64-bit thực tế thì kết quả là 8).
*/