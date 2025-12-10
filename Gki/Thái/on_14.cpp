#include <iostream>
using namespace std;

class Base{
public: 
    void Func(int x = 1, int y = 1);
};

void Base::Func(int x, int y){
    int z = 1, i = 1;
    while (++i <= y) z *= x;   // nhân (y-1) lần vì ++i bắt đầu từ 2
    cout << z;
}
int main(){
    Base obj;
    obj.Func(2, 6);  // x=2, y=6 → z = 2^(6-1) = 32
    return 0;
}
