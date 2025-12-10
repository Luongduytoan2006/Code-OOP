#include <iostream>
using namespace std;

int main()
{
    int x = 1, y = 2; 

    // p1 là con trỏ tới số nguyên hằng (const int*):
    // - Không được phép thay đổi giá trị mà nó trỏ tới thông qua p1
    // - Có thể thay đổi địa chỉ mà p1 trỏ tới
    const int* p1 = &x;  

    // (*p1)++; // ❌ Sai: không thể thay đổi giá trị x qua p1 vì p1 trỏ tới const int
    p1 = &y;      // ✅ Được: thay đổi cho p1 trỏ sang y
    cout << *p1 << endl; // In giá trị y (2)

    // p2 là con trỏ hằng tới số nguyên (int* const):
    // - Không được phép thay đổi địa chỉ của p2
    // - Có thể thay đổi giá trị mà p2 trỏ tới
    int* const p2 = &y;

    // p2 = &x; // ❌ Sai: không thể thay đổi địa chỉ p2
    (*p2)++;      // ✅ Được: thay đổi giá trị y thông qua p2 (y từ 2 → 3)
    cout << *p2;  // In giá trị y sau khi tăng (3)

    return 0;
}
