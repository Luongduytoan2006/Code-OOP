#include <iostream>
using namespace std;
template <int n>
struct Exam
{
    static const int prop = 2 * Exam<n - 1>::prop;
};
template <>
struct Exam<0>
{
    static const int prop = 1;
};
int main()
{
    cout << Exam<10>::prop;
    return 0;
}

// Kết quả: 1024
// Giải thích: Đây là một ví dụ về việc sử dụng mẫu hằng số. Mẫu hằng số này sẽ tính giá trị của 2^n, trong đó n là một số nguyên không âm. Trong trường hợp này, chúng ta muốn tính giá trị của 2^10, nên kết quả sẽ là 1024.