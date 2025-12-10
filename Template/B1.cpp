#include "Vector.h"
#include "Point.h"
#include "Point3D.h"
#include <iostream>
using namespace std;

int main() {
    Vector<int> v1(5, 3);
    v1.Show();

    Vector<double> v2(3.14, 2);
    v2.Show();

    Vector<Point> v3(Point(1, 2), 2);
    v3.Show();

    Vector<Point3D> v4(Point3D(1, 2, 3), 2);
    v4.Show();

    return 0;
}
