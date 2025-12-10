// CÂU 15
#include <iostream>
using namespace std;

template <class T>
T Func(T& var_x, T& var_y)
{
    cout << "1";
    return (var_x > var_y) ? var_x : var_y;
}

// Template Specialization (Chuyên biệt hóa template) cho kiểu int.
// Khi T là int, trình biên dịch sẽ ƯU TIÊN chọn hàm này thay vì template tổng quát ở trên.
template <>
int Func<int>(int& var_x, int& var_y)
{
    cout << "2"; // In ra "2" trước
    return (var_x > var_y) ? var_x : var_y; // 10 > 20 sai -> trả về 20
}

int main()
{
    int var_x = 10, var_y = 20;
    
    // Gọi hàm Func<int>. Do có bản chuyên biệt cho int, nó sẽ nhảy vào hàm dưới.
    cout << Func<int>(var_x, var_y);
    // Thứ tự thực hiện:
    // 1. Vào hàm Func<int>: in ra "2".
    // 2. Hàm trả về 20.
    // 3. Lệnh cout tại main in ra giá trị trả về "20".
    // -> Kết quả trên màn hình: 220
    
    return 0;
}

/**
A. Another Answer
B. Compile Error
C. 220 -> ĐÚNG
D. 120
E. Runtime Error
*/