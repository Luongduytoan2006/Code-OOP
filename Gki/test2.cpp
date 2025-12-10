#include <iostream>
using namespace std;

struct Log {
    static int live;
};
int Log::live = 0;

//================ A: base =================
class ExamA {
public:
    int ax;
    static int sA;                 // static data member (dùng chung)

    ExamA() : ax(0)               { ++Log::live; cout<<"A() ax="<<ax<<"\n"; }
    ExamA(int x) : ax(x) { ++Log::live; cout<<"A(int) ax="<<ax<<"\n"; }
    ExamA(const ExamA& o) : ax(o.ax){ ++Log::live; cout<<"A(copy) ax="<<ax<<"\n"; }

    ExamA& operator=(const ExamA& o){
        cout<<"A::operator= from "<<o.ax<<"\n"; ax=o.ax; return *this;
    }

    // So sánh: cần const, tham số const&
    bool operator<(const ExamA& rhs) const { return ax < rhs.ax; }

    virtual ~ExamA() { --Log::live; cout<<"~A() ax="<<ax<<"\n"; }

    friend ostream& operator<<(ostream& os, const ExamA& a){
        return os<<"[A ax="<<a.ax<<"]";
    }

    // ví dụ static local
    static int nextId(){
        static int id = 0; // giữ giá trị giữa các lần gọi
        return ++id;
    }
};
int ExamA::sA = 100;

//================ B: derived =================
class ExamB : public ExamA {
public:
    int bx;

    ExamB() : ExamA(), bx(10) { cout<<"B() bx="<<bx<<"\n"; }
    ExamB(int a, int b) : ExamA(a), bx(b) { cout<<"B(int,int) bx="<<bx<<"\n"; }

    ExamB(const ExamB& o) : ExamA(o), bx(o.bx){ cout<<"B(copy) bx="<<bx<<"\n"; }

    ExamB& operator=(const ExamB& o){
        cout<<"B::operator=\n";
        ExamA::operator=(o); bx=o.bx; return *this;
    }

    ~ExamB() override { cout<<"~B() bx="<<bx<<"\n"; }

    friend ostream& operator<<(ostream& os, const ExamB& b){
        return os << static_cast<const ExamA&>(b) << " [B bx="<<b.bx<<"]";
    }
};

// Overload operator new/delete để thấy thứ tự gọi
void* operator new(size_t n){
    cout<<"::operator new size="<<n<<"\n";
    return malloc(n);
}
void operator delete(void* p) noexcept {
    cout<<"::operator delete\n";
    free(p);
}

int main() {
    cout<<"== I. Khởi tạo A/B ==\n";
    ExamA a0;            // cần A() public
    ExamA a1(10);        // A(int)
    ExamA a2 = a1;       // copy ctor
    a0 = a1;             // operator=

    cout<<"\n== II. B kế thừa A (thứ tự ctor/dtor) ==\n";
    {
        ExamB b0;        // A() rồi B()
    }                    // ~B() rồi ~A()

    cout<<"\n== III. B(int,int) gọi A(int) ==\n";
    ExamB b1(21,99);     // không lỗi: A(int) chạy trước, rồi B(int,int)

    cout<<"\n== IV. So sánh & in ==\n";
    cout<<(a1 < a2 ? "a1<a2" : "a1>=a2")<<"\n";
    cout<<b1<<"\n";      // cần operator<<

    cout<<"\n== V. new/delete + virtual dtor ==\n";
    ExamA* p = new ExamB(7,8);   // ::operator new -> A(int) -> B(int,int)
    cout<<"*p = "<<*p<<"\n";
    delete p;                    // ~B() -> ~A() -> ::operator delete

    cout<<"\n== VI. static data & static local ==\n";
    cout<<"ExamA::sA="<<ExamA::sA<<"\n";
    cout<<"nextId: "<<ExamA::nextId()<<", "<<ExamA::nextId()<<", "<<ExamA::nextId()<<"\n";

    cout<<"\n== VII. Số đối tượng còn sống (Log::live)="<<Log::live<<"\n";
    return 0;
}
