#include <iostream>
using namespace std;

class Exam
{
public:
    int prop;
};

int main()
{
    Exam obj_x = {10};
    Exam obj_y = obj_x;
    cout << obj_x.prop << obj_y.prop;
    return 0;
}

// Kết quả: 1010
// Giải thích: Trong chương trình này, chúng ta tạo một đối tượng obj_x của lớp Exam với giá trị prop là 10. Sau đó, chúng ta tạo một đối tượng obj_y khác và khởi tạo nó bằng cách sao chép đối tượng obj_x. Khi sao chép một đối tượng, các giá trị của các thuộc tính của đối tượng gốc sẽ được sao chép sang đối tượng mới. Do đó, cả hai đối tượng obj_x và obj_y đều có giá trị prop là 10. Do đó, kết quả là 1010.