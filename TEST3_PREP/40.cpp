// CÂU 40
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Tạo vector có 5 phần tử, khởi tạo mặc định là 0: {0, 0, 0, 0, 0}
    vector<int> myvector(5); 
    
    // p trỏ vào phần tử đầu tiên (index 0) của vector
    int* p = myvector.data(); 
    
    *p = 10; // Gán giá trị tại index 0 là 10. Vector: {10, 0, 0, 0, 0}
    
    ++p; // Tăng con trỏ lên 1 đơn vị -> p trỏ vào index 1
    
    *p = 20; // Gán giá trị tại index 1 là 20. Vector: {10, 20, 0, 0, 0}
    
    // p đang trỏ tại index 1.
    // p[2] tương đương *(p + 2) -> trỏ đến index (1 + 2) = 3.
    p[2] = 100; // Gán giá trị tại index 3 là 100. Vector: {10, 20, 0, 100, 0}
    
    for (unsigned i = 0; i < myvector.size(); ++i)
        cout << ' ' << myvector[i]; // In ra: 10 20 0 100 0
        
    return 0;
}

/**
A. 10 20 0 100 0 -> ĐÚNG
B. Another Answer
C. 10 20
D. 10 20 0 100
E. 10 20 0

Giải thích:
- Ban đầu: {0, 0, 0, 0, 0}
- *p=10 (tại index 0): {10, 0, 0, 0, 0}
- ++p (p trỏ tới index 1).
- *p=20 (tại index 1): {10, 20, 0, 0, 0}
- p[2]=100 (tính từ index 1 + 2 = index 3): {10, 20, 0, 100, 0}
- Kết quả in ra toàn bộ vector.
*/

// CHÚ Ý: Trong C++, p[n] luôn được hiểu là: "Từ vị trí hiện tại của p, đi thêm n bước nữa".