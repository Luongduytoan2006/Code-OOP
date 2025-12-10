#ifndef POINT_H
#define POINT_H

#include <iostream>
using namespace std;

class Point {
protected:
    int x, y;
public:
    Point();
    Point(const int&, const int&);
    friend ostream& operator<<(ostream& o, const Point& obj);
};

Point::Point() : x(0), y(0) {}
Point::Point(const int& x, const int& y) : x(x), y(y) {}

ostream& operator<<(ostream& o, const Point& obj) {
    o << "(" << obj.x << ", " << obj.y << ")";
    return o;
}

#endif // POINT_H
