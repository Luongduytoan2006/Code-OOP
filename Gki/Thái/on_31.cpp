#include <iostream>
using namespace std;
int main() {
    int var_x = 5, var_y = 6, var_z, var_t;
    var_z = var_x, var_y;      // = có độ ưu tiên cao hơn ,  ⇒ (var_z=var_x), var_y;
    cout<< var_z << " "; // 5
    var_t = (var_x, var_y);    // ngoặc buộc dùng toán tử , vì = có độ ưu tiên cao hơn , ⇒ var_t=var_y;
    cout << var_z << var_t;
    return 0;
}
