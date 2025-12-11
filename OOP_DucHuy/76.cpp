#include <iostream>
using namespace std;

class Base
{
public:
    int x;
    Base(int = 1);
    friend Base operator,(int, Base&);
    friend ostream& operator<<(ostream&, Base &); 
};

Base::Base(int x) : x(x) {}

Base operator,(int x, Base &obj)
{
    obj.x = x;
    return obj;
}

ostream& operator<<(ostream& o, Base& obj)
{
    o << (obj.x, obj).x; 
    return o;
}

int main()
{
    Base obj;
    cout << obj;
    system("pause");
    return 0;
}
//Kết quả: 1