// CÂU 20
#include <iostream>
using namespace std;
template<class T>
class Exam
{
    public:
        Exam();
        ~Exam();
};
template<typename T>
Exam<T>::Exam()
{
    cout << "C";
}
template<typename T>
Exam<T>::~Exam()
{
    cout << "D";
}
int main()
{
    // LỖI BIÊN DỊCH (Compile Error):
    // Exam là một class template. Khi khởi tạo đối tượng, BẮT BUỘC phải chỉ định kiểu dữ liệu <T>.
    // Cú pháp đúng phải là: Exam<int> obj; hoặc Exam<float> obj;
    // Do constructor không có tham số nào nên C++ cũng không thể tự suy diễn kiểu (CTAD) được.
    Exam obj;
    return 0;
}

/**
A. Compile Error -> ĐÚNG (Thiếu tham số template)
B. Runtime Error
C. CD
D. DC
E. Another Answer
*/