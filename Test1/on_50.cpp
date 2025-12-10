#include<iostream>
using namespace std;

int main(){
    int var_x = 1, &ref_x = var_x;
    cout << var_x << ", " << ref_x << '\n';
    ref_x = 2;
    cout << var_x << ", " << ref_x << '\n';
    var_x = 3;
    cout << var_x << ", " << ref_x << '\n';
    var_x++;
    cout << var_x << ", " << ref_x << '\n';
    ref_x++;
    cout << var_x << ", " << ref_x << '\n';
    return 0;

}

//ans: 1, 1
//     2, 2