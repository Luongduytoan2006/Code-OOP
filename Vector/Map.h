#ifndef MAP_H
#define MAP_H

#include <iostream>
#include "List.h"
using namespace std;

template<typename K, typename V, template<typename T> class C>
class Map{
    C<K> key;
    C<V> value;
public:
    Map();
    ~Map();
};

template <typename K, typename V, template<typename T> class C>
Map<K, V, C>::Map() {
    cout << "MAP" << endl;
}

template <typename K, typename V, template<typename T> class C>
Map<K, V, C>::~Map() {
    cout << "Destructor MAP" << endl;
}

#endif // MAP_H