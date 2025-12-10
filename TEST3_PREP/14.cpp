// CÂU 14
#include <iostream>
using namespace std;

class SV
{
    protected:
        int MSSV;
    public:
        void getMSSV(int MSSV) { this->MSSV = MSSV; }
        void putMSSV() {} // Hàm rỗng
};

class Test : public SV
{
    protected:
        double mark1, mark2;
    public:
        void getMark(double mark1, double mark2) 
        {
            this->mark1 = mark1;
            this->mark2 = mark2;
        }
        void putMark() {} // Hàm rỗng
};

class Sports // Sports đứng độc lập, không kế thừa SV
{
    protected:
        double score;
    public:
        void getScore(double score) { this->score = score; }
        void putScore() {} // Hàm rỗng
};

// Đa kế thừa: Result kế thừa từ Test (có chứa SV) và Sports
class Result : public Test, public Sports
{
    double total;
    public:
        void display();
};

void Result::display()
{
    // Truy cập được mark1, mark2 (từ Test) và score (từ Sports) do là protected
    this->total = this->mark1 + this->mark2 + this->score;
    
    // Các hàm put... bên dưới là hàm rỗng nên không in gì cả
    putMSSV();
    putMark();
    putScore();
    
    cout << this->total; // In ra tổng điểm
}

int main()
{
    Result SV;
    SV.getMSSV(123);         // MSSV = 123
    SV.getMark(27.5, 33.0);  // mark1 = 27.5, mark2 = 33.0
    SV.getScore(6.0);        // score = 6.0
    
    SV.display();
    // Tính toán: total = 27.5 + 33.0 + 6.0 
    //                  = 60.5 + 6.0 
    //                  = 66.5
    
    return 0;
}

/**
A. Runtime Error
B. 60.5
C. Compile Error
D. 64.5
E. 62.5
F. 66.5 -> ĐÚNG
G. Another Answer

Giải thích:
- Chương trình sử dụng đa kế thừa hợp lệ.
- Class Result cộng tổng các điểm thành phần: 27.5 + 33.0 + 6.0 = 66.5.
- Các hàm put...() được gọi nhưng body rỗng nên không ảnh hưởng kết quả hiển thị.
*/