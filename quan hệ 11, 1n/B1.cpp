#include "Dep.h"
#include <iostream>
using namespace std;

int main() {
    // Teacher t1("NVA", 31);
    // Dep *d = new Dep(t1, "CNTT");
    // cout << d;
    // delete d;

    Teacher *t = new Teacher("NVA", 31);
    Dep *d = new Dep(t, "CNTT");
    cout << *d;
    delete d;
    cout << *t;
    return 0;
}
