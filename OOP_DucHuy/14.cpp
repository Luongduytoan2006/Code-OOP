#include <iostream>
using namespace std;

class SV
{
protected:
    int MSSV;

public:
    void getMSSV(int);
    void putMSSV();
};

void SV::getMSSV(int MSSV)
{
    this->MSSV = MSSV;
}

void SV::putMSSV()
{
    cout << MSSV;
}

class Test : public SV
{
protected:
    double mark1, mark2;

public:
    void getMark(double, double);
    void putMark();
};

void Test::getMark(double mark1, double mark2)
{
    this->mark1 = mark1;
    this->mark2 = mark2;
}

void Test::putMark()
{
    cout << mark1;
    cout << mark2;
}

class Sports
{
protected:
    double score;

public:
    void getScore(double);
    void putScore();
};

void Sports::getScore(double score)
{
    this->score = score;
}

void Sports::putScore()
{
}

class Result : public Test, public Sports
{
    double total;

public:
    void display();
};

void Result::display()
{
    this->total = this->mark1 + this->mark2 + this->score;
    putMSSV();
    putMark();
    putScore();
    cout << this->total;
}

int main()
{
    Result SV;
    SV.getMSSV(123);
    SV.getMark(27.5, 33.0);
    SV.getScore(6.0);
    SV.display();
    return 0;
}

// Kết quả: 12327.5336
// Giải thích: Lớp SV chứa một thuộc tính MSSV và hai phương thức getMSSV() và putMSSV(). Lớp Test kế thừa từ lớp SV và chứa hai thuộc tính mark1 và mark2 và hai phương thức getMark() và putMark(). Lớp Sports chứa một thuộc tính score và hai phương thức getScore() và putScore(). Lớp Result kế thừa từ lớp Test và lớp Sports và chứa một thuộc tính total và một phương thức display(). Khi tạo một đối tượng của lớp Result và gọi phương thức display(), giá trị của MSSV, mark1, mark2, score và total được hiển thị, kết quả là 12327.5336.
