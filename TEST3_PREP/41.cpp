// CÂU 41
#include <iostream>
using namespace std;

class One
{
    public:
        double add(double x)
        {
            return x + 0.1;
        }
};

class Two : public One
{
    public:
        // LƯU Ý QUAN TRỌNG: Ở bài này KHÔNG CÓ dòng "using One::add;" (khác với câu 29 trước đó).
        // Theo quy tắc C++, hàm add(int) ở lớp con sẽ CHE KHUẤT (Hide) hoàn toàn hàm add(double) của lớp cha.
        // Trình biên dịch sẽ không còn nhìn thấy hàm của lớp cha nữa.
        int add(int x)
        {
            return x + 1;
        }
};

int main()
{
    Two obj;
    
    // 1. Gọi obj.add(10):
    // Khớp với Two::add(int) -> Trả về 10 + 1 = 11.
    
    // 2. Gọi obj.add(10.5):
    // Do hàm cha One::add(double) đã bị che khuất, trình biên dịch chỉ tìm thấy Two::add(int).
    // Nó thực hiện ép kiểu ngầm định: (int)10.5 -> 10.
    // Sau đó gọi Two::add(10) -> Trả về 10 + 1 = 11.
    
    cout << obj.add(10) << obj.add(10.5); 
    // Kết quả in liền nhau: 1111
    
    system("pause");
    return 0;
}

/**
A. Another Answer
B. Runtime Error
C. 1111 -> ĐÚNG
D. 1110.6 (Sai, đáp án này chỉ đúng nếu có dùng "using One::add;")
E. Compile Error

Giải thích:
- Đây là hiện tượng "Name Hiding" trong C++. Khi lớp con định nghĩa hàm trùng tên với lớp cha, nó sẽ che khuất tất cả các hàm cùng tên ở lớp cha, bất kể tham số có khác nhau hay không.
- Vì vậy, cả hai lần gọi hàm đều chạy vào `Two::add(int)`.
*/