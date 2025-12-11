#include <iostream>
using namespace std;

template <class T>
class Exam
{
public:
    Exam();
    ~Exam();
    T Func1(T);
    T Func2(T);
};

template <class T>
Exam<T>::Exam()
{
}

template <class T>
Exam<T>::~Exam()
{
}

template <class T>
T Exam<T>::Func1(T var_x)
{
    return var_x;
}

template <class T>
T Exam<T>::Func2(T var_x)
{
    return var_x;
}

int main()
{
    Exam<int> obj_i;
    Exam<double> obj_d;
    cout << obj_i.Func1(200) << obj_d.Func2(3.123);
    return 0;
}

// Kết quả: 2003.123
// Giải thích: Trong chương trình này, lớp mẫu Exam được tạo với một tham số mẫu T. Lớp mẫu này chứa hai hàm thành viên mẫu, Func1() và Func2(). Khi tạo một đối tượng của lớp mẫu Exam với kiểu dữ liệu int, hàm Func1() được gọi với tham số 200 và trả về giá trị 200. Khi tạo một đối tượng của lớp mẫu Exam với kiểu dữ liệu double, hàm Func2() được gọi với tham số 3.123 và trả về giá trị 3.123. Do đó, kết quả là 2003.123.
// Lưu ý: Trong chương trình này, lớp mẫu Exam được tạo với một tham số mẫu T. Do đó, các hàm thành viên của lớp mẫu Exam cũng phải được khai báo với tham số mẫu T.
