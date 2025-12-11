#include <iostream>
using namespace std;

class A
{
public:
    void print();
};
void A::print()
{
    cout << "A::print()";
}
class B : private A
{
public:
    void print();
};
void B::print()
{
    cout << "B::print()";
}
class C : public B
{
public:
    void print();
};
void C::print()
{
    A::print();
}
int main()
{
    C b;
    system("pause");
    b.print();
}

// comeplie error
// giải thích: lớp C kế thừa từ lớp B, lớp B kế thừa từ lớp A. Lớp A chứa một phương thức print() public. Khi lớp C ghi đè phương thức print() của lớp B, nó không thể truy cập đến phương thức print() của lớp A vì nó là private. Do đó, chương trình không biên dịch được.