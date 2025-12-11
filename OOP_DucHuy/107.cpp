#include <iostream>
using namespace std;

class Singleton
{
public:
    static void Init();
    static void Release();
    static Singleton *GetInstance();
    void Method();

private:
    static Singleton *m_Instance;
    Singleton();
    ~Singleton();
};

Singleton *Singleton::m_Instance = NULL;

Singleton::Singleton()
{
}

Singleton::~Singleton()
{
}

Singleton *Singleton::GetInstance()
{
    if (m_Instance == NULL)
        Singleton::Init();
    return m_Instance;
}

void Singleton::Init()
{
    if (m_Instance == NULL)
        m_Instance = new Singleton();
}

void Singleton::Release()
{
    if (m_Instance)
    {
        delete m_Instance;
        m_Instance = NULL;
    }
}

void Singleton::Method()
{
    cout << "Singleton Pattern";
}

int main()
{
    Singleton::GetInstance()->Method();
    system("pause");
    return 0;
}

// Kết quả: Singleton Pattern
// Giải thích: Trong chương trình này, chúng ta sử dụng mẫu thiết kế Singleton để đảm bảo rằng chỉ có một đối tượng của lớp Singleton được tạo ra. Khi chúng ta gọi phương thức GetInstance() để truy cập đối tượng Singleton, m_Instance sẽ được khởi tạo và trả về địa chỉ của đối tượng Singleton. Sau đó, chúng ta gọi phương thức Method() để in ra "Singleton Pattern". Do đó, kết quả là "Singleton Pattern".