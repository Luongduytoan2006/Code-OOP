#include <iostream>
using namespace std;

// Hàm nhận tham số là con trỏ char (không phải const)
void Show(char *str)
{
    cout << str;
}

int main()
{
    const char *str = "DUT"; 

    // Show(str); // ❌ Lỗi biên dịch vì str là const char*, 
                  // còn hàm Show cần char*

    // Dùng const_cast để bỏ const
    Show(const_cast<char*>(str)); // ✅ Ép kiểu bỏ const và truyền vào hàm

    return 0;
}
