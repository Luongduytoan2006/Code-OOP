#include <iostream>
using namespace std;

ostream& operator<<(ostream& o, int /*var_x*/){ return o; }

int main(){
    //cout << 5;   // gọi overload trên, KHÔNG in gì vì ta không đưa 5 vào stream
    cin.get();
    return 0;
}
