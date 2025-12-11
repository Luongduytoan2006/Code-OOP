#include <iostream>
#include <limits>
#include <stdexcept>
using namespace std;
void Func(char var_c)
{
    if (var_c < numeric_limits<char>::max())
        return invalid_argument;
        // Mâu thuẫn kiểu trả về: hàm khai báo trả về void nhưng lại cố gắng trả về một giá trị kiểu invalid_argument.
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

// Kết quả: Compiler Error
// Giải thích: Trong hàm Func(), nếu giá trị của var_c nhỏ hơn giá trị tối đa của kiểu char, một ngoại lệ invalid_argument được trả về. Tuy nhiên, hàm Func() được khai báo trả về một giá trị kiểu void, không phải là một giá trị kiểu invalid_argument. Do đó, chương trình không biên dịch được và sẽ báo lỗi.