// CÂU 35
#include <iostream>
using namespace std;
class Base
{
    public:
        virtual void show();
};
void Base::show()
{
    cout << "B";
}
class Derived : public Base
{
    public:
        void show();
};
void Derived::show()
{
    cout << "D";
}
int main()
{
    Base *bp = new Derived;
    
    // ĐÂY LÀ ĐIỂM MẤU CHỐT:
    // Bình thường bp->show() sẽ gọi Derived::show() (in "D") do cơ chế hàm ảo.
    // NHƯNG ở đây dùng toán tử phạm vi "Base::", nó ép buộc gọi hàm của lớp Base.
    // Việc này vô hiệu hóa tính đa hình (Dynamic Binding) tại dòng này.
    bp->Base::show(); 
    //bp->show();
    
    system("pause");
    return 0;
}

/**
A. D
B. Runtime Error
C. Compile Error
D. Another Answer
E. B -> ĐÚNG (Do gọi tường minh Base::show)
*/