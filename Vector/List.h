#ifndef LIST_H
#define LIST_H

#include<iostream>
using namespace std;

template<typename L>
class List{
public:
    List();
    ~List();
};

template<typename L>
List<L>::List() {
    cout<<"LIST"<<endl;
}

template<typename L>
List<L>::~List() {
    cout<<"Destructor LIST"<<endl;
}

#endif // LIST_H

