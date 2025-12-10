#include <iostream>
using namespace std;

class Base{
    int x;
public:
    Base(int = 0);
    ~Base();
    Base operator+(const Base&);
    Base operator+(int);
    friend int operator+(Base&, Base&);
    friend ostream& operator<<(ostream&, Base&);
};


Base::Base(int x) : x(x) {}

Base::~Base() {}

Base Base::operator+(const Base& obj){
    return Base(this->x + obj.x);
}

Base Base::operator+(int x){
    Base obj;
    obj.x = this->x + x;
    return obj;
}

int operator+(Base& obj1, Base& obj2){
    return obj1.x + obj2.x;
}

ostream& operator<<(ostream& o, Base& obj){
    o << obj.x;
    return o;
}

int main(){
    // Base obj, obj1(4);
    // cout << obj << obj1;
    // int temp = obj + obj1;
    // Base obj2 = obj + obj1;
    // cout << temp << obj2;


    Base test1(1), test2;
    test2 = test1 + 2;
    cout<< test2 << "\n"; // 3
    return 0;
}