#include <iostream>
using namespace std;
class ExamA{
	int var_a;
	public:
		ExamA(int = 1);
		~ExamA();
		int getVar();
};
ExamA::ExamA(int var_a): var_a(var_a) {}
ExamA::~ExamA(){}

int ExamA::getVar(){
	return this->var_a;
}

class ExamB{
	static ExamA obj;
	public:
		ExamB();
		~ExamB();
		static int getVar();
};

ExamA ExamB::obj;

ExamB::ExamB(){}
ExamB::~ExamB(){}

int ExamB::getVar(){
	return ExamB::obj.getVar();
}

int main(){
	ExamB obj;
	cout << ExamB::getVar();
	return 0;
}