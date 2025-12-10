#include <iostream>
using namespace std;
int main() {
    int A[2][3] = {1, 3, 5, 2, 4, 6};
    // A <-> &A[0][0]
    cout << A << ", " << &A[0][0] << '\n';
    // *(A + i) <-> &A[i][0] -> i = 1
    cout << *(A + 1) << ", " << &A[1][0] << '\n';
    // *(A + i) + j <-> &A[i][j] -> i = 1, j = 1
    cout << *(A + 1)  + 1 << ", " << &A[1][1] << '\n';
    // *(*(A + i) + j) <-> A[i][j] -> i = 1, j = 1
    cout << *(*(A + 1) + 1) << ", " << A[1][1] << '\n';
    return 0;
    // int A[2][3] <-> (int*) A[2] <-> (int*) A + 2
} 