#include <iostream>
using namespace std;

class BaseA {
public:
    BaseA();
    BaseA(const BaseA&);
    BaseA operator=(const BaseA&);
};

BaseA::BaseA() { cout << "CBaseA."; }

BaseA::BaseA(const BaseA& obj) { cout << "CCBaseA."; }

BaseA BaseA::operator=(const BaseA& obj) {
    if (this == &obj) return *this;
    cout << "A0BaseA.";
    return *this;
}

class BaseB {
    BaseA obj;
public:
    BaseB(BaseA&);
};

BaseB::BaseB(BaseA& obj) {
    this->obj = obj;
    cout << "CBaseB.";  // in ra cuối cùng
}

int main() {
    BaseA obj1;         // in ra "CBaseA." lần 1
    BaseB obj2(obj1);
    //system("pause");
    return 0;
}
