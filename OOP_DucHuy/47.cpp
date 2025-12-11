#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> a(3, 0);
    vector<int> b(5, 0);
    b = a;
    a = vector<int>();
    cout << int(a.size()) << int(b.size());
    return 0;
}

// Kết quả: 03
// Giải thích: Trong chương trình này, chúng ta tạo hai vector a và b với kích thước ban đầu lần lượt là 3 và 5, tất cả các phần tử của chúng đều được khởi tạo với giá trị 0. Sau đó, chúng ta gán vector a cho vector b, nghĩa là vector b sẽ chứa các phần tử của vector a. Cuối cùng, chúng ta gán vector a cho một vector rỗng, nghĩa là vector a sẽ không chứa bất kỳ phần tử nào. Do đó, kích thước của vector a sẽ là 0 và kích thước của vector b sẽ là 3. Kết quả là 03.