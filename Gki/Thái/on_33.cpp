#include <iostream>
using namespace std;

int Func(int, int);
int Func(int, int, int);

int main() {
    //cout << Func(2, 4);    // Lỗi vì không biết gọi hàm nào (cả 2 đều thỏa)
    cout << Func(2, 4, 6); // Gọi hàm 3 tham số
    return 0;
}

int Func(int x, int y) { return x * y; }
int Func(int x, int y, int z = 5) { return x * y * z; }
