// CÂU 33
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> obj;
    
    // Hàm assign(count, value): gán 'count' phần tử, mỗi phần tử có giá trị là 'value'.
    // Ở đây: tạo 3 phần tử, mỗi phần tử là 4. -> Vector: {4, 4, 4}
    obj.assign(3, 4); 
    
    for (int i = 0; i < obj.size(); i++)
    {
        cout << obj[i]; // In từng phần tử: 4, 4, 4
    }
    return 0;
}

/**
A. Another Answer
B. Compile Error
C. Runtime Error
D. 444 -> ĐÚNG
E. 3333

Giải thích:
- Cú pháp `vector.assign(n, v)` sẽ thay thế nội dung cũ bằng `n` phần tử có giá trị `v`.
- `obj.assign(3, 4)` tạo ra vector có 3 số 4.
- Vòng lặp in ra 3 số 4 liền nhau -> 444.
*/