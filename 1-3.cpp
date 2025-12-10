#include <iostream>
using namespace std;

int main(){
    int A[4] = {1, 4, 6, 8};
    int* p = A;  
    // p ↔ A ↔ &A[0]  (p trỏ tới phần tử đầu tiên của mảng A)

    cout << p << ", " << A << ", " << &A[0] << endl;
    // In ra địa chỉ mà p trỏ tới, địa chỉ mảng A, và địa chỉ phần tử A[0]
    // Cả 3 giá trị này giống nhau vì đều trỏ đến phần tử đầu tiên của mảng.

    cout << p + 1 << ", " << &A[1] << endl;
    // p + 1: dịch chuyển con trỏ sang phần tử tiếp theo (A[1])
    // &A[1]: địa chỉ của phần tử thứ 2 trong mảng
    // Hai giá trị này giống nhau.

    cout << *(p + 1) << ", " << A[1] << endl;
    // *(p + 1): lấy giá trị tại phần tử thứ 2 (A[1])
    // A[1]: truy cập trực tiếp giá trị phần tử thứ 2
    // Cả hai đều in ra 4.

    return 0;
}
