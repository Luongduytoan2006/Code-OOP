#include <iostream>
using namespace std;

class Exam {
public:
    static const int var = 1;
    static int getVar();
};

int Exam::getVar() {
    return Exam::var;
}

int main() {
    cout << Exam::getVar();
    return 0;
}
//Kết quả: 1