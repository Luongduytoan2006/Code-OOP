#include <iostream>
using namespace std;

int main(){
    int x = 10, y = 20;
    int *p1, *p2;
    p1 = &x; p2 = &y;
    cout << "x = " << x << endl;      // x = 10
    cout << "y = " << y << endl;      // y = 20
    cout << "*p1 = " << *p1 << endl;  // *p1 = 10
    cout << "*p2 = " << *p2 << endl;  // *p2 = 20

    *p1 = 50; *p2 = 90;
    cout << "x = " << x << endl;      // x = 50
    cout << "y = " << y << endl;      // y = 90
    cout << "*p1 = " << *p1 << endl;  // *p1 = 50
    cout << "*p2 = " << *p2 << endl;  // *p2 = 90

    *p1 = *p2;
    cout << "x = " << x << endl;      // x = 90
    cout << "y = " << y << endl;      // y = 90
    cout << "*p1 = " << *p1 << endl;  // *p1 = 90
    cout << "*p2 = " << *p2 << endl;  // *p2 = 90

    return 0;   
}