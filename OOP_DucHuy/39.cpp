#include <iostream>
#include <string>
using namespace std;

template <typename T>
void Func(T var_x)
{
    cout << var_x;
}

int main()
{
    double var_x = 5.5;
    string str("IT");
    Func(var_x);
    Func(str);
    return 0;
}

// Kết quả: 5.5IT
// Giải thích: Trong chương trình này, chúng ta định nghĩa một hàm mẫu Func() có một tham số kiểu T. Hàm này sẽ in ra giá trị của tham số được truyền vào. Khi gọi hàm Func() với một số kiểu double và một chuỗi, chúng ta sẽ nhận được kết quả là giá trị của số double và chuỗi đó.