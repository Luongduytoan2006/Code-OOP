#include <iostream>
using namespace std;

class Base{
public:
    Base();
    ~Base();
    void* operator new(size_t size);
    void  operator delete(void* ptr);
};

Base::Base() {
    cout << "Constructor.";
}
Base::~Base() {
    cout << "Destructor.";
}

void* Base::operator new(size_t size){
    cout << "New.";
    void* storage = malloc(size);
    return storage;
}

void Base::operator delete(void* ptr){
    cout << "Delete.";
    free(ptr);
}

int main() {
    Base* ptr = new Base;
    delete ptr;
    // system("pause");
    return 0;
}
