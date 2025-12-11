#include <iostream>
using namespace std;

class Singleton
{
    static Singleton *m_instance;
    Singleton();

public:
    static Singleton *getInstance();
};

Singleton *Singleton::m_instance = NULL;

Singleton::Singleton()
{
}

Singleton *Singleton::getInstance()
{
    if (m_instance == NULL)
        m_instance = new Singleton();
    return m_instance;
}

int main()
{
    Singleton *a = Singleton::getInstance();
    Singleton *b = Singleton::getInstance();
    (a == b) ? cout << "true" : cout << "false";
    system("pause");
    return 0;
}

// Kết quả: true
// Giải thích: Trong chương trình này, chúng ta sử dụng mẫu thiết kế Singleton để đảm bảo rằng chỉ có một đối tượng của lớp Singleton được tạo ra. Khi chúng ta gọi phương thức getInstance() lần đầu tiên, m_instance sẽ được khởi tạo và trả về địa chỉ của đối tượng Singleton. Khi chúng ta gọi phương thức getInstance() lần thứ hai, m_instance đã được khởi tạo trước đó, do đó, chỉ cần trả về địa chỉ của đối tượng Singleton đã được tạo trước đó. Do đó, a và b sẽ trỏ đến cùng một đối tượng và kết quả là "true".