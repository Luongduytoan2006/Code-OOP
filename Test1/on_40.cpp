#include <iostream>
using namespace std;

double Func( double var_x, int var_y, double var_z ){
    int var_m =1;
    double var_n = 1;
    var_n = var_n * ( 1+ var_x * ++var_y*var_z );

    var_m = int(var_m + var_n);
    return var_m;
}


int main(){
    double var_x;
    double Func(double var_x = 5.0, int var_y = 2, double var_z = 2.0);
    var_x = Func();
    cout<<var_x;
    return 0;
}