#include <iostream>
using namespace std;

class Exam {
    static int var; // Static member variable

public:
    Exam(); // Constructor
    void Func(); // Member function
};

// Initialization of static member variable
int Exam::var = 0;

// Constructor definition
Exam::Exam() {
    if (Exam::var == 1) {
        cout << Exam::var;
    } else {
        Exam::var++;
    }
}

// Member function definition
void Exam::Func() {
    cout << Exam::var;
}

int main() {
    Exam obj1; // Create an object of Exam
    obj1.Func();

    Exam obj2; // Create another object of Exam
    obj2.Func();

    return 0;
}
//Kết quả: 111