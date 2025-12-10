#ifndef DOCTOR_H
#define DOCTOR_H

#include <iostream>
#include <string>
#include <vector>
#include "Patient.h"
using namespace std;

class Doctor{
    string named;
    vector<Patient*> vp;
public:
    Doctor(string = "");
    ~Doctor();
    string GetNameD() const;
    void AddPatient(Patient* p);
    friend ostream& operator<<(ostream&, const Doctor&);
};

// Implementation
Doctor::Doctor(string s) : named(s) {}

Doctor::~Doctor() { 
    this->vp.clear(); 
}

string Doctor::GetNameD() const {
    return this->named;
}

void Doctor::AddPatient(Patient* p) {
    this->vp.push_back(p);
    p->AddDoctor(this);
}

ostream& operator<<(ostream& o, const Doctor& d) {
    o << "Doctor: " << d.named << endl;
    for (int i = 0; i < d.vp.size(); i++) {
        o << "  Patient: " << d.vp[i]->GetNameP() << endl;
    }
    return o;
}


ostream& operator<<(ostream& o, const Patient& p) {
    o << "Patient: " << p.GetNameP() << endl;
    for (int i = 0; i < p.vd.size(); i++) {
        o << "  Doctor: " << p.vd[i]->GetNameD() << endl;
    }
    return o;
}

#endif
