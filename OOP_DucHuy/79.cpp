#include <iostream>
using namespace std;

int arr_x[] = { 1200, 200, 2300, 1230, 1543 };
int arr_y[] = { 12, 14, 16, 18, 20 };
int i, var_x = 0;

int main() {
    for (i = 0; i < 5; i++) {
        var_x += arr_x[i];
    }

    for (i = 0; i < 4; i++) {
        var_x += arr_y[i];
    }

    cout << var_x;
    return 0;
}
//Kết quả: 6533