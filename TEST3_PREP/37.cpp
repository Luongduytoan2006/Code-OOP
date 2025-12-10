// CÂU 37
#include <iostream>
using namespace std;

class Base1
{
    protected:
        int SampleDataOne;
    public:
        Base1();
        ~Base1();
        int SampleFunctOne();
};

Base1::Base1()
{
    this->SampleDataOne = 100;
}
Base1::~Base1() { }
int Base1::SampleFunctOne()
{
    return this->SampleDataOne;
}

class Base2
{
    protected:
        int SampleDataTwo;
    public:
        Base2();
        ~Base2();
        int SampleFunctTwo();
};

Base2::Base2()
{
    this->SampleDataTwo = 200;
}
Base2::~Base2() { }
int Base2::SampleFunctTwo()
{
    return this->SampleDataTwo;
}

// Đa kế thừa: Derived1 kế thừa cả Base1 và Base2
class Derived1 : public Base1, public Base2
{
    int MyData;
    public:
        Derived1();
        ~Derived1();
        int MyFunct();
};

Derived1::Derived1()
{
    // Khi tạo Derived1, constructor của Base1 và Base2 sẽ được gọi tự động trước.
    // -> SampleDataOne = 100
    // -> SampleDataTwo = 200
    this->MyData = 300;
}
Derived1::~Derived1() { }
int Derived1::MyFunct()
{
    return (this->MyData + this->SampleDataOne + this->SampleDataTwo);
}

int main()
{
    Base1 SampleObjOne;
    Base2 SampleObjTwo;
    Derived1 SampleObjThree; 
    // SampleObjThree chứa dữ liệu của cả Base1 (100) và Base2 (200).

    // 1. Gọi hàm của Base1 từ đối tượng Derived -> Trả về 100
    // 2. Gọi hàm của Base2 từ đối tượng Derived -> Trả về 200
    cout << SampleObjThree.Base1::SampleFunctOne()
         << SampleObjThree.Base2::SampleFunctTwo();
    
    system("pause");
    return 0;
}

/**
A. Another Answer
B. Compile Error
C. 200100
D. 100
E. 200
F. 100200 -> ĐÚNG
G. Runtime Error

Giải thích:
- Đối tượng `SampleObjThree` kế thừa từ `Base1` (có giá trị 100) và `Base2` (có giá trị 200).
- Lệnh `cout` in ra giá trị hàm `SampleFunctOne` (100) nối tiếp với hàm `SampleFunctTwo` (200).
- Kết quả trên màn hình là chuỗi liền nhau: 100200.
*/