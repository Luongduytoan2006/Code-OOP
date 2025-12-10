// CÂU 21
#include <iostream>
using namespace std;
int main()
{
    int var_i = -12;
    try
    {
        cout << "Inside try" << endl; // 1. In ra dòng đầu tiên
        if (var_i < 0) // -12 < 0 -> Đúng
        {
            throw var_i; // 2. Ném ngoại lệ (-12). Luồng chạy NHẢY NGAY sang catch.
            cout << "After throw" << endl; // Dòng này bị bỏ qua (Dead code)
        }
    }
    catch (int var_i) // Bắt được ngoại lệ kiểu int
    {
        cout << "Exception Caught" << endl; // 3. Thực thi khối catch
    }
    cout << "After catch" << endl; // 4. Sau khi xử lý catch xong, chương trình chạy tiếp xuống đây
    return 0;
}

/**
A. Inside try \n Exception Caught \n After throw
B. Inside try \n After throw \n After catch
C. Inside try \n Exception Caught \n After catch -> ĐÚNG
D. Another Answer
E. Inside try \n Exception Caught \n After throw \n After catch

Giải thích:
- "Inside try" in ra đầu tiên.
- Gặp lệnh `throw`, chương trình ngắt luồng hiện tại và nhảy vào `catch`, bỏ qua lệnh in "After throw".
- Trong `catch`, in ra "Exception Caught".
- Sau khi thoát `catch`, chương trình tiếp tục chạy bình thường và in "After catch".
*/