#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    double x = 126.7;
    cout<<setiosflags(ios::showpoint)<<setprecision(4)<<x;
}

// Có nghĩa là làm tròn đến 2 chữ số trừ trái sang phải
//VD : 126.7, set 2 => ans: 1.3e+02
//VD: 126.74, set 4 => 126.7 (lưu ý làm tròn)