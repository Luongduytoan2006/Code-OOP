// CÂU 1 (Câu 45/50 trong ảnh)
#include<iostream>
using namespace std;

class base{
    int arr[10]; 
    // int kích thước 4 bytes (đề bài cho).
    // Mảng 10 phần tử -> Kích thước class base = 10 * 4 = 40 bytes.
};

class b1 : public base
{ }; 
// Kế thừa base -> b1 chứa 1 bản sao của base. Size b1 = 40 bytes.

class b2 : public base
{ }; 
// Kế thừa base -> b2 chứa 1 bản sao của base. Size b2 = 40 bytes.

class derived : public b1, public b2
{ };
// Đa thừa kế từ b1 và b2.
// Lưu ý từ Review.txt mục 4 (Đa thừa kế): "bị double nhiều lớp".
// Do không dùng kế thừa ảo (virtual inheritance), derived sẽ chứa cả b1 và b2 độc lập.
// Cấu trúc bộ nhớ: [base của b1] + [base của b2]
// Tổng kích thước = 40 + 40 = 80 bytes.

int main()
{
    cout << sizeof(derived);
    system("pause");
    return 0;
}

/*
A. 4
B. 0
C. Another Answer
D. 80 -> ĐÚNG
E. 40
*/