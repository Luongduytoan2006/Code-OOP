#include <iostream>
using namespace std;

class ExamA{
    public:
        virtual ~ExamA();
        void operator delete(void*);
};

ExamA::~ExamA(){}


void ExamA::operator delete(void* ptr){
    cout << "delete ExamA";
}

class ExamB : 
public ExamA{
    public:
        void operator delete(void*);
};

void ExamB::operator delete(void* ptr){
    cout << "delete ExamB";
}

int main(){
    ExamA* ptr = new ExamB;
    delete ptr;
    return 0;
}
