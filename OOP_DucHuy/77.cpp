#include <iostream>
using namespace std;

int main() {
    char arr[8] = {'V', 'I', 'E', 'T', 'N', 'A', 'M', '\0'}; 
    char *ptr;
    ptr = (char*)((arr + 2)[2]); 
    cout << char(ptr); 
    return 0;
}
//Kết quả: Compiled error
main.cpp:7:11: warning: cast to pointer from integer of different size [-Wint-to-pointer-cast]
    7 |     ptr = (char*)((arr + 2)[2]);
      |           ^~~~~~~~~~~~~~~~~~~~~
main.cpp:8:13: error: cast from ‘char*’ to ‘char’ loses precision [-fpermissive]
    8 |     cout << char(ptr);
      |             ^~~~~~~~~