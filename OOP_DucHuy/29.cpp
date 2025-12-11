#include <iostream>
using namespace std;
template <typename T>
class Exam
{
    T var_x;

public:
    static int count;
    Exam();
    ~Exam();
};

template <typename T>
int Exam<T>::count = 0;

template <typename T>
Exam<T>::Exam()
{
    Exam<T>::count++;
}

template <typename T>
Exam<T>::~Exam()
{
}

int main()
{
    Exam<int> obj_x;
    Exam<int> obj_y;
    Exam<double> obj_z;
    cout << Exam<int>::count << " " << Exam<double>::count;
    return 0;
}

// Kết quả: 2 1
// Giải thích: Trong chương trình này, lớp mẫu Exam được tạo với một tham số mẫu T. Một biến tĩnh count được khai báo trong lớp mẫu Exam để đếm số lượng đối tượng được tạo. Khi tạo một đối tượng của lớp mẫu Exam với kiểu dữ liệu int, biến count được tăng lên 1. Khi tạo một đối tượng khác của lớp mẫu Exam với kiểu dữ liệu int, biến count được tăng lên 1 nữa. Khi tạo một đối tượng của lớp mẫu Exam với kiểu dữ liệu double, biến count được tăng lên 1. Do đó, giá trị của count cho kiểu dữ liệu int là 2 và cho kiểu dữ liệu double là 1.