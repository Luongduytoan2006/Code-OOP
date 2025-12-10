#include "MyExp.h"
#include <exception>
#include <iostream>
using namespace std;

int B(const int& x, const int& y){
    try{
        if( y == 0 ) throw MyExp("Loi chia cho 0", 99);
    }
    // dùng & vì nếu không dùng & thì sẽ gọi hàm sao chép, mà hàm sao chép có thể không được định nghĩa.
    //Dùng & lưu kiểu dữ liệu và tiết kiệm bộ nhớ
    catch (const MyExp &e){ 
        cout<<"Bắt trong hàm B: "<<e<<endl;
        //throw;  // Re-throw lại ngoại lệ để hàm gọi nó xử lý tiếp
        throw e;
    }

    return x/y;
}

void A(const int& x, const int& y){

    try {
        int z = B(x, y);
        cout<<"Phép toán được thực thi trong hàm A: "<<z<<endl;
    }
    catch (const MyExp &e){
        cout<<"Bắt trong hàm A: "<<e<<endl;
        throw;  // Re-throw lại ngoại lệ để hàm gọi nó xử lý tiếp
    }
}

int main(){
    int a = 1, b = 0;

    try{
        if( b == 0 ) {
            // throw 1;
            // throw 5.4;
            throw MyExp("Ngu như bò", 100);
            throw Exp("Loi Exp");
        } else {
            cout<<"Phép toán được thực thi: "<<(a/b)<<endl;
        }
    }
    catch (const int &a ){ cout<<"int: "<<a<<endl;}
    catch (const double &a){ cout<<"double: "<<a<<endl;}
    catch (const MyExp &e){ cout<<"MyExp: "<<e<<endl;}
    catch (const Exp &e){ cout<<"Exp: "<<e<<endl;}
    catch (...){ cout<<"Đã bắt được thằng ngu hơn bò"<<endl;}



    try {
        A(a, b);
    }
    catch (const MyExp &e){
        cout<<"Bắt tại main: "<<e<<endl;
    }
    return 0;

}