#include <iostream>
using namespace std;

void Func( int x, int y){
    if( y == 0 ){
        throw "Error!;"
    } else {
        cout<<x<<y;
    }
}

int main(){
    try{
        Func(10,0);
    } catch (char * e ){
        // Lỗi kiểu chuỗi ký tự, const char* thì in ra giá trị chuỗi
        cout<<e;
    }
    return 0;
}


