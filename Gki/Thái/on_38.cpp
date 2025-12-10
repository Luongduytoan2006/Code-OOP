#include <iostream>
using namespace std;
int main() {
    int var_x, var_y = 10;
    var_x = (var_y++, var_y + 100, 999 + var_y);
    // var_y 10 -> 11 -> 111 -> 999 + 11 = 1010
    cout << var_x;
    return 0;
}
