// CÂU 42
#include <iostream>
using namespace std;

class polygon
{
    protected:
        int width, height;
    public:
        void set_values(int a, int b);
};

void polygon::set_values(int a, int b)
{
    this->width = a; 
    this->height = b;
}

class output1
{
    public:
        void output(int);
};

void output1::output(int i)
{
    cout << i; // In ra giá trị i, không có khoảng trắng hay xuống dòng
}

// Đa kế thừa: rectangle kế thừa polygon (dữ liệu) và output1 (hàm in)
class rectangle : public polygon, public output1
{
    public:
        int area();
};

int rectangle::area()
{
    return (this->width * this->height);
}

class triangle : public polygon, public output1
{
    public:
        int area();
};

int triangle::area()
{
    return (this->width * this->height / 2);
}

int main()
{
    rectangle rect;
    triangle trgl;
    
    rect.set_values(4, 5); // rect: width=4, height=5
    trgl.set_values(4, 5); // trgl: width=4, height=5
    
    // 1. Tính rect.area() = 4 * 5 = 20.
    // 2. Gọi rect.output(20) -> In "20".
    rect.output(rect.area()); 
    
    // 3. Tính trgl.area() = (4 * 5) / 2 = 10.
    // 4. Gọi trgl.output(10) -> In "10".
    trgl.output(trgl.area());
    
    // Kết quả nối chuỗi: 2010
    
    system("pause");
    return 0;
}

/**
A. 2010 -> ĐÚNG
B. 20
C. None of the mentioned
D. 10

Giải thích:
- Hàm `output` in số nguyên ra màn hình mà không thêm ký tự phân cách nào.
- Diện tích hình chữ nhật là 20.
- Diện tích hình tam giác là 10.
- Hai lệnh in thực hiện liên tiếp tạo thành chuỗi "2010".
*/