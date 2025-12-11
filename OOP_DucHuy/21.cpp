#include <iostream>
using namespace std;

template <class T, class U, class V = double>
class Exam
{
    T prop_x;
    U prop_y;
    V prop_z;
};

int main()
{
    Exam<int, int> obj_ii;
    Exam<double, double> obj_dd;
    cout << sizeof(obj_ii) << sizeof(obj_dd);
    return 0;
}

// Kết quả: 1624
// Giải thích: Lớp Exam có ba tham số mẫu, T, U và V. Trong trường hợp này, hai đối tượng obj_ii và obj_dd được tạo với các kiểu dữ liệu khác nhau. Khi tạo một đối tượng của lớp Exam với kiểu dữ liệu int và int, kích thước của đối tượng này là 16 byte. Khi tạo một đối tượng của lớp Exam với kiểu dữ liệu double và double, kích thước của đối tượng này là 24 byte.