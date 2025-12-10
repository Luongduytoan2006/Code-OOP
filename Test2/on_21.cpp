#include <iostream>
using namespace std;

class Exam {
    static int count;
public:
    Exam();
    ~Exam();
    // Thêm operator+ để tạo một đối tượng mới
    Exam operator+(const Exam&) const { return Exam(); }

    void Func() { cout << Exam::count; }
    friend ostream& operator<<(ostream& o, const Exam& obj) {
        o << obj.count;   // cùng một biến static
        return o;
    }
};

int Exam::count = 0;
Exam::Exam()  { Exam::count++; }
Exam::~Exam() { Exam::count--; }

int main() {
    Exam obj_x, obj_y;          // count = 2
    Exam obj_z = obj_x + obj_y; // tạo thêm 1 Exam -> count = 3
    cout << obj_x << obj_y << obj_z; // in 333
    return 0;
}
