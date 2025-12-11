#include <iostream>
using namespace std;

const int Max = 4;

class Exam {
    int arr[Max];

public:
    int& operator[](const int& index) {
        if (index >= 0 && index < Max) {
            int temp;
            for (int i = 0; i < Max; ++i) {
                if (*(this->arr + i) > *(this->arr + index)) {
                    temp = *(this->arr + index);
                    *(this->arr + index) = *(this->arr + i);
                    *(this->arr + i) = temp;
                }
            }
        }
        return *(this->arr + index);
    }
};

int main() {
    Exam obj;

    for (int i = 0; i < Max; ++i) {
        obj[i] = i * 10; // Initialize obj[i] with values 0, 10, 20, 30
    }

    for (int i = 0; i < Max; ++i) {
        int temp = obj[i]; 
        cout << temp << " "; // Print the modified values of obj[i]
    }

    return 0;
}
//Kết quả: 30 30 30 30