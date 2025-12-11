#include <iostream>
using namespace std;

class Base
{
private:
    void *operator new(size_t size) {}   // line 1
    void *operator new[](size_t size) {} // line 2
};

int main()
{
    Base *ptr1 = new Base;     // line 3
    Base *ptr2 = new Base[10]; // line 4
    system("pause");
    return 0;
}

// Kết quả: Lỗi biên dịch
// Giải thích: Do lớp Base không có hàm dựng mặc định nên dòng 3 và dòng 4 s
