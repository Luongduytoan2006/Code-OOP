#include "Vector.h"
#include "List.h"
#include "Point.h"
#include "Point3D.h"
#include "Map.h"
#include <iostream>
using namespace std;

template class Vector<int>;
template class Vector<double>;
template class Vector<Point>;
template class Vector<Point3D>;

template class Map<int, double, List>;
template class Map<int, double, Vector>;