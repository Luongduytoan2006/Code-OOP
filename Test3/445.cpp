#include <iostream>
using namespace std;

class Base{
    public:
    int prop_b;
    Base(int);
};

Base::Base(int prop_b): prop_b(prop_b) {}

class Derived : public Base{
    public:
    int prop_b;
    int prop_d;
    Derived(int, int);
};

Derived::Derived(int prop_b, int prop_d) : Base(prop_b), prop_d(prop_d) {}

void Func(){
    throw Derived(10,20);
}

int main(){
    try{
        Func();
    } catch (Derived & e){
        cout<<"D";
    } catch (Base & e){
        cout<<"B";
    }
    return 0;
}