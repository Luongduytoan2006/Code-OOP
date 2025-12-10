#include <iostream>
using namespace std;

class Base{
    int x;
public:
    Base(int x = 1);
    friend int operator,(Base&, int);
};

Base ::Base(int x) : x(x) {}

int operator,(Base& obj, int x){
    return x;
}

int main(){
    Base obj;
    int x = 2;
    cout << operator,(obj, x);
    cout << (obj, 5);
    return 0;
}