#include <bits/stdc++.h>
using namespace std;

int Func(int,int);
int Func(int, int, int);
// CE khi gọi Func(int, int, int = 10 ) vì không có hàm nào phù hợp (do 2 hàm ngang nhau, compile ko biết chọn hàm nào)

int main(){
    cout<<Func(2,4);
    //cout<<Func(2,4,6);
}

int Func(int a, int b){
    return a*b;
}

int Func(int a, int b, int c = 6){
    return a*b*c;
}