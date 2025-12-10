#include <iostream>
using namespace std;

void Func( int x, int y = 4 ){
    cout<<x<<y<<endl;
}

int main(){
    Func(2,3);
    Func(5);
    return 0;
}