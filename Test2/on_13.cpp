#include <iostream>
#include <cstdlib>
using namespace std;

class Base {
public:
    Base();
    ~Base();

    // overload cấp phát/thu hồi bộ nhớ cho lớp
    void* operator new(size_t size);
    void  operator delete(void* ptr);
};

Base::Base() {
    cout << "Constructor.";
}

Base::~Base() {
    cout << "Destructor.";
}

void* Base::operator new(size_t size) {
    cout << "New.";
    void* storage = std::malloc(size);
    if (!storage) throw std::bad_alloc();
    return storage;
}

void Base::operator delete(void* ptr) {
    cout << "Delete.";
    std::free(ptr);
}

int main() {
    Base* ptr = new Base; // New.Constructor.
    delete ptr;           // Destructor.Delete.
    return 0;
}
