#include <iostream>
using namespace std;

int main()
{
    int var_x = 1;

    switch (var_x)
    {
        case 1: cout << "One";
        case 2: cout << "Two";
        case 3: cout << "Three";
        default: cout << "Default";
    }

    return 0;
}
//Kết quả: OneTwoThreeDefault