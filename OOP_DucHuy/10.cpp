#include <iostream>
using namespace std;

class Base
{
public:
    virtual void print() const = 0;
};

class DerivedA : public Base
{
public:
    void print() const;
};
void DerivedA::print() const
{
    cout << "A";
}

class DerivedB : public Base
{
public:
    void print() const;
};
void DerivedB::print() const
{
    cout << "B";
}

class DerivedC : public DerivedA, public DerivedB
{
public:
    void print() const;
};
void DerivedC::print() const
{
    DerivedB::print();
}

int main()
{
    int i;
    DerivedC obj_c;
    DerivedA obj_a;
    DerivedB obj_b;
    Base *array[3];
    array[0] = &obj_c;
    array[1] = &obj_a;
    array[2] = &obj_b;
    array[i]->print();
    return 0;
}

// Kết quả: Compiler Error
// Giải thích: Lỗi tại dòng "array[0] = &obj_c". Do không dùng thừa kế ảo (virtual inheritance), DerivedC chứa 2 bản sao riêng biệt của Base (một từ A, một từ B). Trình biên dịch không xác định được cần trỏ về bản sao Base nào => Lỗi "ambiguous base class".