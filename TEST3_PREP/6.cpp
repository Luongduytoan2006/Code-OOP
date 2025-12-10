// CÂU 6
#include <iostream>
using namespace std;
struct a
{
    int count;
};
struct b
{
    int* value;
};
struct c : public a, public b // struct c kế thừa từ a và b (mặc định là public)
{
};
int main()
{
    c* p = new c; // Tạo đối tượng c
    
    // Gán giá trị 0 cho con trỏ int*. Trong C++, 0 được hiểu là NULL pointer.
    // Đây là phép gán hợp lệ, chỉ là set địa chỉ con trỏ về NULL, không phải dereference (*value).
    p->value = 0; 
    
    cout << "DUT"; // In ra chuỗi
    system("pause");
    return 0;
}

/**
A. None of the mentioned
B. DUT -> ĐÚNG
C. Compile Error
D. Runtime Error

Giải thích:
- Code biên dịch và chạy bình thường.
- Struct mặc định access là public nên truy cập p->value hợp lệ.
- Gán pointer bằng 0 (NULL) là hợp lệ.
- Không có lỗi runtime vì không có hành động dereference con trỏ null nào cả.
*/