// CÂU 29
#include <iostream>
using namespace std;
class One
{
    public:
        double add(double x){
            return x + 0.1;
        }
};
class Two : public One
{
    public:
        // QUAN TRỌNG: Lệnh này đưa các hàm add() của class One vào phạm vi của class Two.
        // Nếu không có dòng này, hàm add(int) của Two sẽ CHE KHUẤT (hide) hàm add(double) của One.
        using One::add; 
        
        int add(int x)
        {
            return x + 1;
        }
};
int main()
{
    Two obj;
    
    // obj.add(10): Tham số là int -> Gọi Two::add(int) -> Trả về 11
    // obj.add(10.5): Tham số là double -> Nhờ 'using', nó tìm thấy One::add(double) phù hợp nhất -> Trả về 10.6
    cout << obj.add(10) << obj.add(10.5); 
    // Kết quả in liền nhau: 1110.6
    
    system("pause");
    return 0;
}

/**
A. Compile Error
B. 1111
C. 1110.6 -> ĐÚNG
D. Runtime Error
E. Another Answer
*/