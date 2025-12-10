// ===== ĐỀ MẪU THEO PHONG CÁCH LỚP/PHƯƠNG THỨC KHAI BÁO TRONG CLASS,
// ===== ĐỊNH NGHĨA Ở NGOÀI VỚI TOÁN TỬ PHẠM VI :: =====================

#include <iostream>
using namespace std;

// ------------ KHAI BÁO LỚP CƠ SỞ ExamA --------------------------------
class ExamA
{
    int ax;                          // private
public:
    static int sA;                   // static data member dùng chung

    ExamA();                         // ctor mặc định
    explicit ExamA(int);             // ctor tham số
    ExamA(const ExamA&);             // copy ctor
    ExamA& operator=(const ExamA&);  // phép gán

    bool operator<(const ExamA&) const;     // so sánh
    virtual ~ExamA();                       // dtor ảo để delete qua A*

    static int nextId();                    // static local demo
    int get() const;                        // hàm const
    friend ostream& operator<<(ostream&, const ExamA&); // in đối tượng
};

// ------------ KHAI BÁO LỚP DẪN XUẤT ExamB : public ExamA ---------------
class ExamB : public ExamA
{
    int bx;
public:
    ExamB();                          // ctor mặc định
    ExamB(int, int);                  // ctor 2 tham số (gọi A(int) trước)
    ExamB(const ExamB&);              // copy ctor
    ExamB& operator=(const ExamB&);   // gán
    ~ExamB();                         // dtor (override)

    friend ostream& operator<<(ostream&, const ExamB&); // in đối tượng B
};

// ------------ KHAI BÁO HÀM TỰ DO ĐỂ MINH HỌA TRUYỀN THAM SỐ -------------
void takeA_by_value(ExamA a);              // copy ctor
void takeA_by_const_ref(const ExamA& a);   // không copy
void takeA_ptr_const(const ExamA* p);      // con trỏ tới hằng dữ liệu

// ================== ĐỊNH NGHĨA HÀM Ở PHẦN DƯỚI =========================

// ----- static data member của ExamA -----
int ExamA::sA = 100;

// ----- ExamA: constructors / operators / methods -----
ExamA::ExamA() : ax(0) {
    cout << "ExamA() ax=" << ax << "\n";
}

ExamA::ExamA(int x) : ax(x) {
    cout << "ExamA(int) ax=" << ax << "\n";
}

ExamA::ExamA(const ExamA& o) : ax(o.ax) {
    cout << "ExamA(copy) ax=" << ax << "\n";
}

ExamA& ExamA::operator=(const ExamA& rhs) {
    cout << "ExamA::operator= from " << rhs.ax << "\n";
    if (this != &rhs) ax = rhs.ax;
    return *this;
}

bool ExamA::operator<(const ExamA& rhs) const {
    // lưu ý: hàm thành viên const, tham số const&
    return ax < rhs.ax;
}

ExamA::~ExamA() {
    cout << "~ExamA() ax=" << ax << "\n";
}

int ExamA::nextId() {
    static int id = 0;        // static local: khởi tạo 1 lần, giữ giá trị
    return ++id;
}

int ExamA::get() const {
    return ax;
}

ostream& operator<<(ostream& o, const ExamA& a) {
    return o << "[A ax=" << a.ax << "]";
}

// ----- ExamB: constructors / operators / methods -----
ExamB::ExamB() : ExamA(), bx(10) {
    // Nếu ExamA KHÔNG có default ctor mà bạn không gọi rõ -> CE
    cout << "ExamB() bx=" << bx << "\n";
}

ExamB::ExamB(int a, int b) : ExamA(a), bx(b) {
    // GỌI A(int) TRƯỚC, rồi tới phần B.
    cout << "ExamB(int,int) bx=" << bx << "\n";
}

ExamB::ExamB(const ExamB& o) : ExamA(o), bx(o.bx) {
    cout << "ExamB(copy) bx=" << bx << "\n";
}

ExamB& ExamB::operator=(const ExamB& rhs) {
    cout << "ExamB::operator=\n";
    if (this != &rhs) {
        ExamA::operator=(rhs); // gán phần A
        bx = rhs.bx;           // gán phần B
    }
    return *this;
}

ExamB::~ExamB() {
    cout << "~ExamB() bx=" << bx << "\n";
}

ostream& operator<<(ostream& o, const ExamB& b) {
    // tái dùng in của A
    o << static_cast<const ExamA&>(b);
    return o << " [B bx=" << b.bx << "]";
}

// ----- Hàm tự do minh họa truyền tham số -----
void takeA_by_value(ExamA a) {
    cout << "takeA_by_value: " << a << "\n";
}
void takeA_by_const_ref(const ExamA& a) {
    cout << "takeA_by_const_ref: " << a << "\n";
}
void takeA_ptr_const(const ExamA* p) {
    cout << "takeA_ptr_const: " << *p << "\n";
}

// ================================ MAIN ==================================
int main()
{
    cout << "I) Tao A tu dong / tham so / sao chep / gan\n";
    ExamA a0;              // ExamA()
    ExamA a1(10);          // ExamA(int)
    ExamA a2 = a1;         // ExamA(copy)
    a0 = a1;               // ExamA::operator=

    cout << "\nII) Tao B: thu tu goi ctor/dtor (B : public A)\n";
    {
        ExamB b0;          // A() -> B()
        cout << "b0 = " << b0 << "\n";
    }                      // ~B() -> ~A()

    cout << "\nIII) B(int,int) goi A(int)\n";
    ExamB b1(21, 99);      // A(int) -> B(int,int)

    cout << "\nIV) So sanh va in\n";
    cout << (a1 < a2 ? "a1<a2" : "a1>=a2") << "\n";
    cout << b1 << "\n";    // can operator<< (neu bo se CE)

    cout << "\nV) Truyen tham so (value/const&/ptr)\n";
    takeA_by_value(a1);        // copy ctor
    takeA_by_const_ref(a1);    // khong copy
    takeA_ptr_const(&a1);      // khong copy

    cout << "\nVI) new/delete qua con tro co so (dtor ao)\n";
    ExamA* p = new ExamB(7, 8);   // goi A(int) -> B(int,int)
    cout << "*p = " << *p << "\n";
    delete p;                     // ~B() -> ~A()  (nhờ ~ExamA là virtual)

    cout << "\nVII) static data & static local\n";
    cout << "ExamA::sA = " << ExamA::sA << "\n";
    cout << "nextId: " << ExamA::nextId() << ", "
         << ExamA::nextId() << ", " << ExamA::nextId() << "\n";

    // ====== CÁC DÒNG CE (bật thử để thấy lỗi, nhớ đọc chú thích) ======
    // 1) Nếu bỏ operator<< ở trên, dòng cout << b1; sẽ CE (không tìm thấy <<)
    // 2) Nếu ExamA KHÔNG có default ctor mà ExamB() không gọi ExamA(...): CE.
    // 3) Nếu viết operator= của B thành free function: CE (operator= phải là member).

    return 0;
}
