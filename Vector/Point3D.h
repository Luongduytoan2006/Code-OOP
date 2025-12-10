#ifndef POINT3D_H
#define POINT3D_H

#include <iostream>
#include "Point.h"
using namespace std;

class Point3D : public Point {
    int z;
public:
    Point3D();
    Point3D(const int&, const int&, const int&);
    friend ostream& operator<<(ostream& o, const Point3D& obj);
};

Point3D::Point3D() : Point(), z(0) {}
Point3D::Point3D(const int& x, const int& y, const int& z) : Point(x, y), z(z) {}

ostream& operator<<(ostream& o, const Point3D& obj) {
    o << "(" << obj.x << ", " << obj.y << ", " << obj.z << ")";
    return o;
}

#endif 
