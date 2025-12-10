// CÂU 3
#include <iostream>
using namespace std;

template<typename T>
void loopIt(T x)
{
    int count = 3;
    T val[3];
    for (int ii = 0; ii < count; ii++)
    {
        val[ii] = x++; // Gán giá trị hiện tại của x vào val[ii] rồi mới tăng x lên 1 (Post-increment)
        cout << val[ii]; // In giá trị vừa gán
    }
}; // Dấu ; ở đây dư nhưng trình biên dịch thường bỏ qua (coi là empty declaration)

int main()
{
    float xx = 2.1;
    loopIt(xx); // Gọi hàm với T=float, x=2.1 (copy value)
    // Vòng lặp 1: val[0]=2.1, x tăng lên 3.1 -> In: 2.1
    // Vòng lặp 2: val[1]=3.1, x tăng lên 4.1 -> In: 3.1
    // Vòng lặp 3: val[2]=4.1, x tăng lên 5.1 -> In: 4.1
    // Kết quả nối chuỗi: 2.13.14.1
    
    system("pause");
    return 0;
}

/**
A. 3.2
B. Compile Error
C. 2.1
D. Runtime Error
E. 3.1
F. Another Answer
G. 2.13.14.1 -> ĐÚNG (Do toán tử x++ trả về giá trị cũ rồi mới cộng, và x là float nên cộng 1.0)
*/