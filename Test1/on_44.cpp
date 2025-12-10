#include <iostream>
#include <string>
using namespace std;

int main(){
    char arr[] = { "CNTT" };
    char *ptr = arr;
    *ptr = 'D';
    cout<<*ptr<<endl;
    return 0;
}