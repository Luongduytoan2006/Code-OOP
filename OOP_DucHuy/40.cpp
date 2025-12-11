#include <iostream>
#include <exception>
using namespace std;

void FuncExp()
{
    cout << "Exception:";
    throw;
}

void Func() throw(int, bad_exception)
{
    throw 'x';
}

int main(void)
{
    set_unexpected(FuncExp);
    try
    {
        Func();
    }
    catch (int)
    {
        cout << "int";
    }
    catch (bad_exception be)
    {
        cout << "bad_exception";
    }
    catch (...)
    {
        cout << "other exception";
    }
    return 0;
}

// Kết quả: Exception:other exception
// Giải thích: Trong chương trình này, chúng ta đang cố gắng ném một ký tự từ hàm Func(). Trong hàm main(), chúng ta đã sử dụng set_unexpected() để đặt hàm xử lý ngoại lệ không mong đợi là FuncExp(). Tuy nhiên, trong trường hợp này, chúng ta không bắt ngoại lệ nào từ hàm Func(), do đó hàm xử lý ngoại lệ không mong đợi FuncExp() sẽ được gọi. Hàm này sẽ in ra "Exception:" và sau đó ném một ngoại lệ không mong đợi. Trong trường hợp này, chúng ta không bắt ngoại lệ nào, do đó khối catch(...) sẽ được thực thi và in ra "other exception". Do đó, kết quả là Exception:other exception.