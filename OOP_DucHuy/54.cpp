#include <iostream>
using namespace std;

double Func(double, double, double = 0, double = 0, double = 0);

int main() {
    double var_x = 2.3;
    cout << Func(var_x, 7) << Func(var_x, 7, 6);
    return 0;
}

double Func(double var_x, double var_y, double var_z, double var_m, double var_n) {
    return var_y + (var_z + (var_m + var_n * var_x) * var_x) * var_x;
}
//Kết quả: 720.8