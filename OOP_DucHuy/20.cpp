#include <iostream>
using namespace std;

class ClassA
{
protected:
    int x;

public:
    ClassA();
    friend void Show();
};

ClassA::ClassA()
{
    this->x = 0;
}

class ClassB : public ClassA
{
public:
    ClassB();

private:
    int y;
};

ClassB::ClassB() : y(0)
{
}

void Show()
{
    ClassA obj1;
    ClassB obj2;
    cout << obj1.x << obj2.y;
}

int main()
{
    Show();
    system("pause");
    return 0;
}
