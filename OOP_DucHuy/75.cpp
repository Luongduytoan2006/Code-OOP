#include <iostream>
using namespace std;

class Base
{
public:
    int x;
    Base();
    ~Base();
    void Show() const; 
};

Base::Base()
{
    this->x = 1;
}

void Base::Show() const 
{
    cout << this->x;
}

int main()
{
    Base obj;
    obj.Show();
    system("pause");
    return 0;
}
//Kết quả: Compiled error