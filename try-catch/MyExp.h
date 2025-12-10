#include "Exp.h"

class MyExp : public Exp {
    int n;
public:
    MyExp(string = "", const int& = 1);
    ~MyExp();
    friend ostream& operator<<(ostream& os, const MyExp& e);
};


MyExp::MyExp(string s, const int& x) : Exp(s), n(x) {
}

MyExp::~MyExp() {
}

ostream& operator<<(ostream& os, const MyExp& e) {
    os << "MyExp Operator: " << e.msg << ", n = " << e.n;
    return os;
}