// CÂU 26
#include <iostream>
using namespace std;

template <class T>
class Exam
{
    public:
        void putPropY();
        static T prop_x; // Biến tĩnh công khai
    private:
        static T prop_y; // Biến tĩnh riêng tư
};

template <class T>
void Exam<T>::putPropY(){
    // In giá trị hiện tại của prop_y rồi mới tăng lên (Post-increment).
    cout << Exam<T>::prop_y++; 
}

// Khởi tạo biến static bên ngoài class
template <class T>
T Exam<T>::prop_x = 1;

template <class T>
T Exam<T>::prop_y = 1.2;

int main()
{
    // 1. Khởi tạo obj_i kiểu int.
    // Exam<int>::prop_x = 1
    // Exam<int>::prop_y = (int)1.2 = 1 (bị ép kiểu xuống số nguyên)
    Exam<int> obj_i;

    // 2. Khởi tạo obj_d kiểu double.
    // Exam<double>::prop_x = 1.0
    // Exam<double>::prop_y = 1.2
    // Lưu ý: Biến static của template là RIÊNG BIỆT cho từng kiểu dữ liệu (T).
    Exam<double> obj_d;

    // 3. Gọi hàm putPropY của obj_i (int)
    // In ra prop_y (1), sau đó tăng lên 2. -> Output: 1
    obj_i.putPropY();

    // 4. In ra prop_x của obj_i (int) -> Output: 1
    cout << obj_i.prop_x;

    // 5. Gọi hàm putPropY của obj_d (double)
    // In ra prop_y (1.2), sau đó tăng lên 2.2. -> Output: 1.2
    obj_d.putPropY();

    // Kết quả nối chuỗi: 1 -> 1 -> 1.2 ==> 111.2
    return 0;
}

/**
A. 11.2
B. Runtime Error
C. 1
D. Another Answer
E. 1.2
F. Compile Error
G. 111.2 -> ĐÚNG
*/