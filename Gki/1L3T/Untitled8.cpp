#include <iostream>
using namespace std;
class Exam{  // => CE do private hết
	int var;
	Exam();
	~Exam();
};
Exam::Exam() : var(5){}
Exam::~Exam(){}

int main(){
	Exam* ptr = new Exam;
	cout << ptr->var;
	return 0;
}