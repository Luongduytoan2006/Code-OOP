// CÂU 23
#include <iostream>
using namespace std;
class ExamA
{
    mutable int prop;
    public:
        ExamA();
        ~ExamA();
};
ExamA::ExamA()
{
    cout << "IT"; // 1. Constructor lớp cha (Base) chạy đầu tiên
}
ExamA::~ExamA()
{
    cout << "ITF"; // 4. Destructor lớp cha chạy cuối cùng
}

class ExamB : public ExamA
{
    public:
        ExamB();
        ~ExamB();
};
ExamB::ExamB()
{
    cout << "DUT"; // 2. Constructor lớp con (Derived) chạy sau lớp cha
}
ExamB::~ExamB()
{
    cout << "DHBK"; // 3. Destructor lớp con chạy trước khi hủy đối tượng
}

int main()
{
    ExamB obj; 
    // Khởi tạo: ExamA() -> ExamB(). Màn hình: ITDUT
    
    return 0;
    // Kết thúc main -> Hủy obj.
    // Thứ tự hủy: Ngược lại với khởi tạo (Con trước -> Cha sau).
    // ~ExamB() -> "DHBK"
    // ~ExamA() -> "ITF"
    // Tổng kết quả: ITDUTDHBKITF
}

/**
A. Another Answer
B. ITDUTDHBKITF -> ĐÚNG
C. ITDUTITFDHBK
D. ITFDHBK
E. ITDUT
*/