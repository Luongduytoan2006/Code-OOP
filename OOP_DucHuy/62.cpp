#include <iostream>
using namespace std;

class Base
{
public:
    int x;
    Base(short);
    Base(int);
    Base(char);
    ~Base();
};

Base::Base(short x) {
    cout << "Short";
}

Base::Base(int x) {
    cout << "Int";
}

Base::Base(char x) {
    cout << "Char";
}

Base::~Base() {
    cout << "Final";
}

int main()
{
    Base *ptr = new Base('@');
    system("pause");
    return 0;
}
//Kết quả: char