// CÂU 43
#include <iostream>
using namespace std;
struct BaseA
{
    int prop_a;
};
struct BaseB
{
    int* prop_b;
};
// BaseC kế thừa từ BaseA và BaseB.
// Trong C++, struct mặc định kế thừa là public (khác class là private).
struct BaseC : public BaseA, public BaseB
{
};

int main()
{
    BaseC* ptr = new BaseC;
    
    // Gán giá trị 0 (tương đương NULL) cho biến con trỏ prop_b.
    // Đây là phép gán địa chỉ, KHÔNG PHẢI truy cập vùng nhớ (dereference *prop_b = 0).
    // -> Hoàn toàn hợp lệ và an toàn.
    ptr->prop_b = 0; 
    
    cout << "Inherited"; // In ra màn hình
    return 0;
}

/**
A. Inherited -> ĐÚNG
B. Runtime Error
C. Another Answer
D. Compile Error

Giải thích:
- Code sử dụng `struct` nên các thành viên và kế thừa mặc định là `public`.
- Việc gán `ptr->prop_b = 0` chỉ đơn giản là set con trỏ về `NULL`. Không có lỗi truy cập bộ nhớ trái phép nào xảy ra.
- Chương trình chạy thông suốt và in ra "Inherited".
*/