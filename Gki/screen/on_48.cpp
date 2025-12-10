#include <iostream>
using namespace std;

class BaseA {
    int x;
};

class BaseB {
    int   x;
    BaseA obj;
public:
    operator BaseA();
    operator int();
};

BaseB::operator BaseA() { return this->obj; }
BaseB::operator int()   { return this->x;   }

void Func(int x)  { }
void Func(BaseA o){ }

int main() {
    BaseB obj;
    //Func(obj);        // CE vì có 2 hàm Func() đều có thể gọi được
    // system("pause");
    return 0;
}
