#include <iostream>
using namespace std;

class Base
{
public:
    Base();
    ~Base();
    void *operator new(size_t);
    void operator delete(void *);
};

Base::Base()
{
    cout << "Constructor.";
}

Base::~Base()
{
    cout << "Destructor.";
}

void *Base::operator new(size_t size)
{
    cout << "New.";
    void *storage = malloc(size);
    return storage;
}

void Base::operator delete(void *ptr)
{
    cout << "Delete.";
    free(ptr);
}

int main()
{
    Base *ptr = new Base;
    delete ptr;
    system("pause");
    return 0;
}

// Kết quả: New.Constructor.Delete.
// Giải thích: Trong hàm main, khi khởi tạo con trỏ ptr, hàm new sẽ được gọi. Trong hàm dựng của lớp Base, Constructor sẽ được gọi. Khi giải phóng con trỏ ptr, hàm delete sẽ được gọi. Do đó kết quả là New.Constructor.Delete.