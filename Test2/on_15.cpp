#include <iostream>
using namespace std;

class Exam {
    double prop_length;
    double prop_breadth;
    double prop_height;
public:
    ~Exam() {}

    double getVolume() {
        return this->prop_length * this->prop_breadth * this->prop_height;
    }
    void setLength(double prop_length)  { this->prop_length  = prop_length;  }
    void setBreadth(double prop_breadth){ this->prop_breadth = prop_breadth; }
    void setHeight(double prop_height)  { this->prop_height  = prop_height;  }

    Exam operator+(const Exam& obj) {
        return Exam{
            this->prop_length  + obj.prop_length,
            this->prop_breadth + obj.prop_breadth,
            this->prop_height  + obj.prop_height
        };
    }

    // thêm constructor tiện dụng cho operator+
    Exam(double L=0, double B=0, double H=0)
        : prop_length(L), prop_breadth(B), prop_height(H) {}
};

int main() {
    Exam obj_x;
    Exam obj_y;
    Exam obj_z;
    double volume = 0.0;

    obj_x.setLength(6.0);
    obj_x.setBreadth(7.0);
    obj_x.setHeight(5.0);

    obj_y.setLength(12.0);
    obj_y.setBreadth(13.0);
    obj_y.setHeight(10.0);

    volume = obj_x.getVolume();
    cout << volume;                // 210

    volume = obj_y.getVolume();
    cout << volume;                // 1560

    obj_z = obj_x + obj_y;         // (18,20,15)
    volume = obj_z.getVolume();
    cout << volume;                // 5400

    return 0;
}
