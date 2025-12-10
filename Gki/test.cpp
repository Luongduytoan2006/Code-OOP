// ONE-FILE DEMO: ExamA & ExamB – tất tần tật các tình huống hay hỏi
#include <iostream>
#include <string>
using namespace std;

static int GID = 0; // đếm ID để dễ theo dõi đối tượng

//============================= ExamA (Lớp cơ sở) =============================
class ExamA {
    int secret_ = -777; // private để minh họa friend << của B cũng không thấy nếu không kế thừa
public:
    int ax = -1;

    // [A1] Ctor mặc định
    ExamA() : ax(0) {
        cout << "ExamA()  id=" << ++GID << "  ax=" << ax << "\n";
    }

    // [A2] Ctor tham số
    ExamA(int x) : ax(x) {
        cout << "ExamA(int)  ax=" << ax << "\n";
    }

    // [A3] Copy ctor
    ExamA(const ExamA& other) : ax(other.ax) {
        cout << "ExamA(copy)  ax=" << ax << "\n";
    }

    // [A4] operator= (gán)
    ExamA& operator=(const ExamA& rhs) {
        cout << "ExamA::operator= from ax=" << rhs.ax << "\n";
        if (this != &rhs) ax = rhs.ax;
        return *this;
    }

    // [A5] Dtor (virtual để xóa qua con trỏ cơ sở an toàn)
    virtual ~ExamA() {
        cout << "~ExamA()  ax=" << ax << "\n";
    }

    // [A6] In đối tượng A
    friend ostream& operator<<(ostream& os, const ExamA& a) {
        return os << "[A ax=" << a.ax << "]";
    }
};

//============================= ExamB (Lớp dẫn xuất) ==========================
class ExamB : public ExamA {
public:
    int bx = -2;

    // Thứ tự khởi tạo: luôn gọi ctor của A trước, rồi mới đến B
    ExamB() : ExamA(), bx(100) {
        cout << "ExamB()       bx=" << bx << "\n";
    }

    explicit ExamB(int a, int b) : ExamA(a), bx(b) {
        cout << "ExamB(int,int) ax=" << a << "  bx=" << bx << "\n";
    }

    // Copy ctor của B -> gọi copy ctor A trước
    ExamB(const ExamB& other) : ExamA(other), bx(other.bx) {
        cout << "ExamB(copy)    bx=" << bx << "\n";
    }

    // Gán của B
    ExamB& operator=(const ExamB& rhs) {
        cout << "ExamB::operator=\n";
        if (this != &rhs) {
            ExamA::operator=(rhs); // gán phần A
            bx = rhs.bx;           // gán phần B
        }
        return *this;
    }

    ~ExamB() override {
        cout << "~ExamB()       bx=" << bx << "\n";
    }

    // In B (gọi lại in A để tái dùng)
    friend ostream& operator<<(ostream& os, const ExamB& b) {
        os << static_cast<const ExamA&>(b); // in phần A
        return os << " [B bx=" << b.bx << "]";
    }
};

//============================= Các hàm minh họa ==============================
void takeA_by_value(ExamA a) {       // copy (gọi copy ctor A)
    cout << "takeA_by_value: " << a << "\n";
}
void takeA_by_const_ref(const ExamA& a) { // không copy
    cout << "takeA_by_const_ref: " << a << "\n";
}
void takeA_ptr_const(const ExamA* p) {    // con trỏ tới hằng dữ liệu
    cout << "takeA_ptr_const: " << *p << "\n";
}

int main() {
    cout << "================ [I] TẠO ĐỐI TƯỢNG TỰ ĐỘNG =================\n";
    ExamA a0;                 // ExamA(): default
    ExamA a1(10);             // ExamA(int)
    ExamA a2 = a1;            // copy initialization -> ExamA(copy)
    ExamA a3(0); a3 = a1;     // assignment -> ExamA::operator=

    cout << "\n=========== [II] KẾ THỪA: THỨ TỰ CTOR/DTOR (B : public A) ==========\n";
    {
        ExamB b0;             // Gọi A() trước, rồi B()
        cout << "b0 => " << b0 << "\n";
    }                         // Hủy theo thứ tự ngược: ~B() rồi ~A()

    cout << "\n=========== [III] CTOR THAM SỐ / COPY / GÁN CỦA B ==========\n";
    ExamB b1(21, 99);         // ExamA(int) trước, rồi ExamB(int,int)
    ExamB b2 = b1;            // ExamA(copy) rồi ExamB(copy)
    ExamB b3;  b3 = b1;       // ExamB::operator= (gọi A::operator= bên trong)

    cout << "\n=========== [IV] NEW / DELETE – XÓA QUA CON TRỎ CƠ SỞ ==========\n";
    ExamA* p = new ExamB(7, 8);   // upcast: con trỏ A trỏ B
    cout << "*p   => " << *p << "\n";
    delete p;                     // nhờ ~ExamA virtual -> gọi ~ExamB rồi ~ExamA

    cout << "\n=========== [V] TRUYỀN THAM SỐ: copy vs const& vs con trỏ ==========\n";
    takeA_by_value(a1);           // copy ctor A
    takeA_by_const_ref(a1);       // không copy
    takeA_ptr_const(&a1);         // con trỏ tới A, không copy

    cout << "\n=========== [VI] UPCAST NGẦM ĐỊNH B -> A ====================\n";
    ExamB b4(30, 40);
    ExamA up1 = b4;               // object slicing: chỉ phần A được copy
    cout << "up1 (sliced) => " << up1 << "\n";
    takeA_by_const_ref(b4);       // upcast reference: KHÔNG slicing, không copy

    cout << "\n=========== [VII] KHÔNG OVERLOAD << THÌ SAO? =================\n";
    // Nếu bạn xóa/giấu friend operator<< ở ExamA/ExamB
    // thì dòng dưới sẽ KHÔNG biên dịch:
    // cout << a1 << "\n"; // ❌ lỗi: no match for operator<<

    cout << "\n=========== [VIII] new[] / delete[] (nhắc lại) ===============\n";
    ExamB* arr = new ExamB[2];    // gọi A(), B() cho từng phần tử
    delete[] arr;                  // hủy từng phần tử: ~B(), ~A() cho 2 phần tử

    cout << "\n============================== DONE ===========================\n";
    return 0;
}
