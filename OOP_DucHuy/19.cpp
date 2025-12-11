#include <iostream>
using namespace std;

int main()
{
    int num = 3;
    try
    {
        if (num == 1)
        {
            throw 5;
        }
        if (num == 2)
        {
            throw 1.1f;
        }
        if (num != 1 || num != 2)
        {
            throw string("Error!");
        }
    }
    catch (int a)
    {
        cout << a;
    }
    catch (float b)
    {
        cout << b;
    }
    catch (...)
    {
        cout << "Error!";
    }
    return 0;
}

// Kết quả: Error!
// Giải thích: Trong khối try, nếu giá trị của num bằng 1, một ngoại lệ kiểu int được ném. Nếu giá trị của num bằng 2, một ngoại lệ kiểu float được ném. Trong trường hợp còn lại, một ngoại lệ kiểu string được ném. Trong trường hợp này, giá trị của num là 3, không phù hợp với bất kỳ điều kiện nào, do đó một ngoại lệ mặc định được ném. Khối catch(...) được sử dụng để bắt bất kỳ ngoại lệ nào không được bắt bởi các khối catch khác. Do đó, thông báo lỗi "Error!" được hiển thị.