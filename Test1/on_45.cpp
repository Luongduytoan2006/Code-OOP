#include <iostream>
using namespace std;

int main(){
    int arr[] = {1, 2, 3, 4 };
    int *p = arr;
    for( int i=0; i<4; i++ ) arr[i] += arr[i]; // arr = {2, 4, 6, 8}

    // *(p+i) == arr[i]
    for( int i=0; i<4; i++ ) cout << *(p+i) - i;
}