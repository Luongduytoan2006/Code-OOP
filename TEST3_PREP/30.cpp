// CÂU 30
#include <iostream>
// Thực tế cần #include <cstdlib> cho malloc/free, nhưng trình biên dịch trong đề thi thường châm chước.
using namespace std;

class ExamA
{
    public:
        // Overload toán tử new
        void* operator new(size_t) throw (const char*);
        // Overload toán tử delete
        void operator delete(void*);
};

void* ExamA::operator new(size_t size)
{
    void* ptr = malloc(size);
    if (ptr == 0)
        throw "Operator new ExamA"; // Chỉ ném ngoại lệ nếu cấp phát thất bại (hiếm gặp)
    return ptr; // Cấp phát thành công thì trả về pointer, KHÔNG in gì cả.
}

void ExamA::operator delete(void* ptr)
{
    cout << "Operator delete ExamA" << endl; // In ra khi delete
    free(ptr);
}

class ExamB
{
    int arr[100];
    public:
        // Overload toán tử delete (phiên bản có tham số size - sized delete)
        void operator delete(void*, size_t) throw (const char*);
};

void ExamB::operator delete(void* ptr, size_t size)
{
    cout << "Operator delete ExamB" << endl; // In ra khi delete
    free(ptr);
}

int main()
{
    ExamA* ptr_a = new ExamA; // Gọi ExamA::new (thành công) -> Không in gì.
    delete ptr_a;             // Gọi ExamA::delete -> In: "Operator delete ExamA"

    ExamB* ptr_b = new ExamB; // ExamB không overload new -> Dùng new mặc định -> Không in gì.
    delete ptr_b;             // Gọi ExamB::delete -> In: "Operator delete ExamB"

    return 0;
}

/**
A. Compile Error
B. Operator new ExamA \n Operator delete ExamA \n Operator delete ExamB
C. Operator delete ExamA \n Operator delete ExamB -> ĐÚNG
D. Another Answer
E. Runtime Error

Giải thích:
- Khi `new ExamA`: Hàm `operator new` được gọi, cấp phát thành công và trả về pointer, không có lệnh `cout` nào trong đó được thực thi.
- Khi `delete ptr_a`: Hàm `operator delete` của ExamA được gọi -> In "Operator delete ExamA".
- Khi `new ExamB`: Dùng `operator new` mặc định của hệ thống -> Không in gì.
- Khi `delete ptr_b`: Hàm `operator delete` của ExamB được gọi -> In "Operator delete ExamB".
*/