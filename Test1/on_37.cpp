#include <iostream>
using namespace std;

void Func( int x, int y){
    x = 2;
    y =1;
}

int main(){
    int x=1;
    Func(x,x);
    cout<<x;
    return 0;
}