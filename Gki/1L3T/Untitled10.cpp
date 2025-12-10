#include <iostream>
using namespace std;
class Exam
{
	int var1, var2;
	public:
		Exam();
		Exam(int, int);
		~Exam();
		void Func();
};
Exam::Exam()
{ 

}
Exam::Exam(int var1, int var2)
{
	Exam obj;
	obj.var1 = var1;
	obj.var2 = var2;
	obj.Func();
	*this = obj;
}
Exam::~Exam()
{

}
void Exam::Func()
{
	cout << this->var1 << this->var2;
}
int main()
{
	Exam obj(1, 2);
	obj.Func();
	return 0;
}