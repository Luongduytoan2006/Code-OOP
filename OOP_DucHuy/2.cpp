#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> obj;
    obj.assign(3, 4);
    for (int i = 0; i < obj.size(); i++)
    {
        cout << obj[i];
    }
    return 0;
}

// Kết quả: 444
// Giải thích: Hàm assign() được sử dụng để gán giá trị cho các phần tử của vector. Trong trường hợp này, giá trị 4 được gán cho 3 phần tử của vector. Do đó, kết quả là 444.