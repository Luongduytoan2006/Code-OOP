#include <iostream>
using namespace std;
struct A
{
    virtual void f()
    {
        cout << "A";
    }
};
struct B : A
{
    virtual void f()
    {
        cout << "B";
    }
};
struct C : A
{
    virtual void f()
    {
        cout << "C";
    }
};
void f(A *arg)
{
    B *bp = dynamic_cast<B *>(arg);
    C *cp = dynamic_cast<C *>(arg);
    if (bp)
        bp->f();
    else if (cp)
        cp->f();
    else
        arg->f();
}
int main()
{
    A aobj;
    C cobj;
    A *ap = &cobj;
    A *ap2 = &aobj;
    f(ap);
    f(ap2);
    system("pause");
    return 0;
}

// Kết quả: CC
// Giải thích: Trong hàm f(), con trỏ arg được chuyển đổi thành con trỏ bp của lớp dẫn xuất B và con trỏ cp của lớp dẫn xuất C bằng cách sử dụng dynamic_cast. Nếu chuyển đổi thành công, hàm f() sẽ gọi hàm f() của lớp dẫn xuất tương ứng. Trong trường hợp này, con trỏ ap trỏ đến một đối tượng của lớp dẫn xuất C, do đó hàm f() sẽ gọi hàm f() của lớp dẫn xuất C, kết quả là C. Con trỏ ap2 trỏ đến một đối tượng của lớp cơ sở A, do đó hàm f() sẽ gọi hàm f() của lớp cơ sở A, kết quả là C.