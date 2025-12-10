#include <iostream>
#include "Doctor.h"
#include "Patient.h"
using namespace std;

int main() {
    Doctor* d1 = new Doctor("BS1");
    Doctor* d2 = new Doctor("BS2");

    Patient* p1 = new Patient("BN1");
    Patient* p2 = new Patient("BN2");
    Patient* p3 = new Patient("BN3");

    p1->AddDoctor(d1);
    p1->AddDoctor(d2);
    p2->AddDoctor(d1);

    cout << *d1 << endl;
    cout << *d2 << endl;
    cout << *p1 << endl;

    delete d1;
    delete d2;
    delete p1;
    delete p2;
    delete p3;

    return 0;
}