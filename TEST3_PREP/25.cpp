// CÂU 25
#include <iostream>
using namespace std;
class Exam
{
    public:
        // LỖI BIÊN DỊCH (Compile Error):
        // Constructor KHÔNG THỂ là hàm ảo (virtual).
        // Lý do: Cơ chế hàm ảo (vtable) cần đối tượng đã được tạo ra mới hoạt động được.
        // Trong khi đó, constructor là hàm ĐANG tạo ra đối tượng.
        virtual Exam(); 
};
Exam::Exam()
{ }
int main()
{
    system("pause");
    return 0;
}

/**
A. Không -> ĐÚNG (Vì C++ cấm virtual constructor)
B. Có
*/