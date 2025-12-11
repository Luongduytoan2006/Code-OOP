#include <iostream>
using namespace std;

int main() {
    cout << (int var_x = 5) << (int var_y = 6);
    return 0;
}
//Kết quả: compiled error
main.cpp:5:14: error: expected primary-expression before ‘int’
    5 |     cout << (int var_x = 5) << (int var_y = 6);
      |              ^~~
main.cpp:5:14: error: expected ‘)’ before ‘int’
    5 |     cout << (int var_x = 5) << (int var_y = 6);
      |             ~^~~
      |              )