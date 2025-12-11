#include <iostream>
using namespace std;

class Base
{
public:
    int x;
    Base(int = 1);
    friend int operator,(Base&, int); 
};

Base::Base(int x) : x(x) {}

int operator,(Base& o, int x) {
    return x; 
}

int main()
{
    Base obj;
    int x = 2;
    cout << (obj, x); 
    system("pause");
    return 0;
}
//Kết quả: 2