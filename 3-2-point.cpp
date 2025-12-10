//ĐỊnh nghĩ lớp

#include "3-2-point.h"
#include <iostream>
using namespace std;

void Point::TT(int x){
    xVal += x;
    yVal += x;
}

void Point::show(){
    cout << "Toa do x: " << xVal << ", Toa do y: " << yVal << endl;
}

