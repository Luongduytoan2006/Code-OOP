#include <iostream>
using namespace std;

class Exam {
public:
    void Func1();
    void Func2();
};

void Exam::Func1() {}

void Exam::Func2() {}

int main() {
    Exam obj;
    cout << sizeof(obj);
    return 0;
}
//Kết quả: 1