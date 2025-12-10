#include <iostream>
using namespace std;

int Func( int x=5 , int y=10 , int z=5){
    return x+y+z;
}

int main(){
    cout<<Func(10,2,3);
    return 0;
}

// Các biến nhập vô lun theo thứ tự
// Nếu x đã có mà hàm có số đầu tiên (chỉ thiếu) thì là của x => confict
//VD: Func( int x =10, int y ) ,gọi Func(10), Func(10,2), Func(3)=> lỗi
//VD: Func( int x , int y =10 ),gọi Func(10), Func(10,2) (vẫn chấp nhận), Func(3)=> ans: 20, 12, 13
// 3 biến tự mò vì đang test thấy lắm case ảo