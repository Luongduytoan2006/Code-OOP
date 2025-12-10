#include <iostream>
using namespace std;
int main(){
    char arr[20];
    int i;
    for (i = 0; i < 10; i++){
        *(arr + i) = 65 + i;   // đặt ký tự 'A'..'J' vào arr[i]
        *(arr + i) = '\0';     // NGAY SAU ĐÓ lại đặt '\0' vào arr[i]
        cout << arr;           // in chuỗi tính từ arr[0] đến '\0' đầu tiên
    }
    return 0;
}
