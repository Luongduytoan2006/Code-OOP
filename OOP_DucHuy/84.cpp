#include <iostream>
using namespace std;

int main() {
    int var_x = 10;

    int* ptr = &var_x + 1;     // Statement 1
    int* ptr2 = &var_x;        // Statement 2
    &&var_x = 40;             // Statement 3

    return 0;
}
//Statement 1 and 2 are wrong.