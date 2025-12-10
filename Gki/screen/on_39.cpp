// #include <iostream>
// using namespace std;

// ostream& operator<<(ostream& o, int var_x) {
//     return o;
// }

// int main() {
//     cout << 5;
//     cin.get();
//     return 0;
// }

// => Lỗi nè

#include <iostream>
using namespace std;

ostream& operator<<(ostream& o, int var_x) {
    o.operator<<(var_x); 
    return o;
}

int main() {
    ::operator<<(cout, 5);
    cin.get();
    return 0;
}