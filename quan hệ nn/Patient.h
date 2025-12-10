#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Doctor;

class Patient{
    string namep;
    vector<Doctor*> vd;
public:
    Patient(string = "");
    ~Patient();
    string GetNameP() const;
    void AddDoctor(Doctor*);
    friend ostream& operator<<(ostream&, const Patient&);
};

Patient::Patient(string s) : namep(s) {}
Patient::~Patient() { this->vd.clear(); }

string Patient::GetNameP() const {
    return this->namep;
}

void Patient::AddDoctor(Doctor* d) {
    this->vd.push_back(d);
}


#endif 