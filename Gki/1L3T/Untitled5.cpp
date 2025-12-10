#include <iostream>
using namespace std;

class Exam{
    static int count;
public:
    Exam& Func();
    ~Exam();
};

int Exam::count = 0;

Exam& Exam::Func(){
    Exam::count++;          // tăng bộ đếm tĩnh dùng chung
    cout << Exam::count;    // in giá trị hiện tại
    return *this;           // trả về tham chiếu để chain tiếp
}

Exam::~Exam(){}

int main(){
    Exam obj;               // (1) tạo đối tượng obj
    obj.Func().Func().Func().Func(); // (2) gọi chain 4 lần
    return 0;               // (3) kết thúc -> hủy obj
}
