// CÂU 28
#include <iostream>
#include <exception>
using namespace std;
int main()
{
    try
    {
        // Cấp phát động mảng 1000 số double.
        // Kích thước = 1000 * 8 bytes = 8000 bytes (~7.8 KB).
        // Đây là lượng bộ nhớ rất nhỏ, nên việc cấp phát sẽ THÀNH CÔNG trên hầu hết các máy tính.
        double* ptr = new double[1000]; 
        
        cout << "Memory allocated"; // Dòng này được thực thi.
    }
    catch (exception & e)
    {
        // Chỉ nhảy vào đây nếu ném ra ngoại lệ std::bad_alloc (khi hết RAM).
        // Với 1000 phần tử thì gần như không bao giờ xảy ra lỗi này.
        cout << "Exception arised";
    }
    return 0;
}

/**
A. Depends on the computer memory
B. Exception arised
C. Another Answer
D. Memory allocatedException arised
E. Memory allocated -> ĐÚNG (Alloc thành công -> In ra thông báo -> Kết thúc try -> Bỏ qua catch)
*/