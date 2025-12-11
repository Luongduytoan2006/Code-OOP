#include <iostream>
using namespace std;

class bowl
{
public:
    int apples;
    int oranges;
};

int count_fruit(bowl *begin, bowl *end, int bowl::*fruit)
{
    int count = 0;
    for (bowl *iterator = begin; iterator != end; ++iterator)
        count += iterator->*fruit;
    return count;
}

int main()
{
    bowl bowls[2] = {{1, 2}, {3, 5}};
    cout << "I have " << count_fruit(bowls, bowls + 2, &bowl::apples) << " apples" << endl;
    cout << "I have " << count_fruit(bowls, bowls + 2, &bowl::oranges) << " oranges" << endl;
    return 0;
}

// Kết quả:
// I have 4 apples
// I have 7 oranges
// Giải thích: Trong chương trình này, chúng ta định nghĩa một lớp bowl với hai thuộc tính apples và oranges. Chúng ta cũng định nghĩa một hàm count_fruit() để đếm số lượng quả trong các tô. Hàm này nhận ba tham số: con trỏ đến tô đầu tiên, con trỏ đến tô cuối cùng và con trỏ đến thành viên dữ liệu của lớp bowl. Hàm này sẽ trả về tổng số quả trong tất cả các tô từ tô đầu tiên đến tô cuối cùng. Trong hàm main(), chúng ta tạo một mảng bowls chứa hai tô và sử dụng hàm count_fruit() để đếm số lượng quả táo và cam trong các tô. Kết quả là "I have 4 apples" và "I have 7 oranges".