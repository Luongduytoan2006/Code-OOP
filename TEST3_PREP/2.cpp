// CÂU 2
#include <iostream>
using namespace std;
class X
{
public: X()
{
    cout << "X"; // 1. Constructor lớp cha chạy trước
}
    ~X()
    {
    cout << "~X"; // 4. Cuối cùng gọi destructor lớp cha
    }
};

class Y : public X
{
public: Y()
{
    cout << "Y"; // 2. Sau đó đến constructor lớp con
}
    ~Y()
    {
    cout << "~Y"; // 3. Khi hủy, gọi destructor lớp con trước (theo Review.txt: hàm hủy: gọi lớp con -> lớp cha) 
    }
};

int main()
{
    Y obj; 
    // Khởi tạo obj: Gọi X() -> in "X", gọi Y() -> in "Y" => Màn hình: XY
    
    system("pause");
    return 0;
    // Kết thúc main, obj bị hủy: Gọi ~Y() -> in "~Y", gọi ~X() -> in "~X" => Tiếp theo: ~Y~X
    // Tổng kết quả: XY~Y~X
}

/**
A. Another Answer
B. XY~Y~X -> ĐÚNG
C. Runtime Error
*/