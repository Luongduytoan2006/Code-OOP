#include <iostream>
using namespace std;

const int SIZE = 10;

class Exam {
    int arr[SIZE];
public:
    Exam();
    ~Exam() {}
    int& operator[](const int& index);
};

Exam::Exam() {
    for (int i = 0; i < SIZE; ++i) {
        this->arr[i] = i;
    }
}

int& Exam::operator[](const int& index) {
    static int temp = 0;        // nơi trả về an toàn khi vượt biên
    if (index > SIZE) {         // chú ý: > SIZE, không phải >=
        return temp;
    }
    return this->arr[index];    // -> arr[0] = 0
}

int main() {
    Exam obj;
    cout << obj[5] << obj[12];  // -> 5 rồi 0 => "50"
    return 0;
}
