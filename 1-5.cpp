#include <iostream>
using namespace std;

int sum(int a, int b){
    return a + b;
}

void sort(int *p, int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(*(p + i) > *(p + j)){
                int temp = *(p + i);
                *(p + i) = *(p + j);
                *(p + j) = temp;
            }
        }
    }
}

int main(){
    int (*p)(int, int);
    p = sum;
    cout << sum(1,2) << ", " << p(1,2)<<endl;
    int a[4] = {2,1,4,3};
    sort(a, 4);
    for( int i = 0; i < 4; i++){
        cout << a[i] << " ";
    }
    cout<<endl;
    return 0;
}