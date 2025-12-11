#include <iostream>
using namespace std;

class Base
{
public:
    int x;
};

int main()
{
    Base *ptr = new Base();

    (*ptr).x = 1;
    cout << (*ptr).x << " " << ptr->x;

    ptr->x = 2;
    cout << (*ptr).x << " " << ptr->x;

    system("pause");
    return 0;
}
//Kết quả : 1 12 2