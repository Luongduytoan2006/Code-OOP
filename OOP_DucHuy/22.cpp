#include <iostream>
#include <string>
using namespace std;

int main()
{
    try
    {
        char *ptr;
        strcpy(ptr, "ITF");
    }
    catch (const exception &e)
    {
    }
    return 0;
}

// Kết quả: Compiler Error
// Giải thích: Trong khối try, hàm strcpy() được sử dụng để sao chép chuỗi "ITF" vào con trỏ ptr. Tuy nhiên, con trỏ ptr không được khởi tạo và không trỏ đến bất kỳ vùng nhớ nào. Do đó, khi cố gắng sao chép chuỗi vào con trỏ ptr, chương trình sẽ không biên dịch được và sẽ báo lỗi.