#include <iostream>
using namespace std;
void Func_Empty() throw()
{
    cout << "1";
}
void Func_Type() throw(int)
{
    cout << "2";
    throw(1);
}
int main()
{
    try
    {
        Func_Empty();
        Func_Type();
    }
    catch (int)
    {
        cout << "3";
    }
    return 0;
}

// Kết quả: 12
// Giải thích: Trong hàm Func_Empty(), không có ngoại lệ nào được ném. Do đó, hàm này không bị giới hạn bởi bất kỳ điều kiện nào. Trong hàm Func_Type(), một ngoại lệ kiểu int được ném. Tuy nhiên, hàm này chỉ được phép ném ngoại lệ kiểu int. Do đó, ngoại lệ kiểu int được ném và chương trình kết thúc sau khi ngoại lệ được ném.