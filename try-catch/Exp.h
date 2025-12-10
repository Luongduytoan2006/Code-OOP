#include <iostream>
#include <string.h>
using namespace std;


class Exp{
protected:
    string msg;
public: 
    Exp(string = "");
    ~Exp();
    friend ostream& operator<<(ostream& os, const Exp& e);
};

Exp::Exp(string s) : msg(s) {
}

Exp::~Exp() {
}

ostream& operator<<(ostream& os, const Exp& e) {
    os << "Exp Operator: " << e.msg;
    return os;
}