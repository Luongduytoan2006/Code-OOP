#include <iostream>
#include <exception>
using namespace std;
int main()
{
    try
    {
        double *ptr = new double[1000];
        cout << "Memory allocated";
    }
    catch (exception &e)
    {
        cout << "Exception arised";
    }
    return 0;
}

// Kết quả: Memory allocated
// Giải thích: Trong chương trình này, chúng ta cố gắng cấp phát một mảng 1000 phần tử kiểu double. Nếu cấp phát bị thất bại, một ngoại lệ sẽ được ném và chúng ta sẽ bắt nó trong khối catch. Tuy nhiên, trong trường hợp này, cấp phát không thất bại, do đó thông điệp "Memory allocated