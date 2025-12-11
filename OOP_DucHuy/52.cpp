#include <iostream>
using namespace std;

class Base
{
    int x;
public:
    Base(int = 1);
    friend void operator<<(ostream&, Base&);
};

Base::Base(int x) : x(x) {}

void operator<<(ostream& o, Base& obj)
{
    o << obj.x;
}

int main()
{
    Base obj(2);
    cout << obj;
    system("pause");
    return 0;
}
//Kết quả: 2