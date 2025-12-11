#include <iostream>
#include <limits>
#include <stdexcept>
using namespace std;
void Func(int c)
{
    if (c < numeric_limits<char>::max())
        throw invalid_argument("Error!");
    else
    {
        cout << "Executed";
    }
}
int main()
{
    try
    {
        Func(256);
    }
    catch (invalid_argument &e)
    {
        cerr << e.what();
        return -1;
    }
    return 0;
}

// Kết quả: Executed
// Giải thích: Vì 256 lớn hơn giá trị tối đa của kiểu char (thường là 127 hoặc 255), điều kiện if bị sai. Chương trình bỏ qua lệnh throw, chạy vào nhánh else và in ra "Executed".