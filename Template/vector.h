#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
using namespace std;

template <typename T>
class Vector {
    T *p;
    int n;
public:
    Vector(const T&, const int& = 2);
    Vector (const Vector<T>&);
    ~Vector();
    void Show();
};

// Template implementation phải ở cùng file với khai báo
template <typename T>
Vector<T>::Vector(const T& t, const int& n) : n(n) {
    this->p = new T[this->n];
    for( int i=0; i<this->n; i++ ){
        *(this->p+i) = t;
    }
}

template <typename T>
Vector<T>::Vector(const Vector<T>& obj) : n(obj.n) {
    this->p = new T[this->n];
    for( int i=0; i<this->n; i++ ){
        *(this->p+i) = *(obj.p+i);
    }
}

template <typename T>
Vector<T>::~Vector() {
    delete[] this->p;
}

template <typename T>
void Vector<T>::Show() {
    for( int i=0; i<this->n; i++ ){
        cout << *(this->p+i) << " ";
    }
    cout << endl;
}

#endif // VECTOR_H