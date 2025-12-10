#ifndef LECTURER_H
#define LECTURER_H

#include <iostream>

#include "Person.h"
#include "mystring.h"
using namespace std;

class Lecturer : public Person {
private:
    char* lecturerID;
    char* rank;

public:
    Lecturer();
    Lecturer(const char* name, int age, const char* address, bool gender, const char* lecturerID, const char* rank);
    ~Lecturer();

    char* getLecturerID() const;
    char* getRank() const;

    void setLecturerID(const char* lecturerID);
    void setRank(const char* rank);

    static char* generateLecturerID(const char* fullName);
    bool isValidLecturerID(const char* id) const;

    friend ostream& operator<<(ostream& os, const Lecturer& l);
    friend istream& operator>>(istream& is, Lecturer& l);
};

#endif
