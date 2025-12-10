#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include "mystring.h"
using namespace std;

class Person
{
protected:
    char *name;
    int age;
    char *address;
    bool gender; // true – nam, false – nữ

public:
    Person();
    Person(const char *name, int age, const char *address, bool gender);
    ~Person();

    char *getName() const;
    int getAge() const;
    char *getAddress() const;
    bool getGender() const;

    void setName(const char *name);
    void setAge(int age);
    void setAddress(const char *address);
    void setGender(bool gender);

    friend ostream &operator<<(ostream &os, const Person &p);
    friend istream &operator>>(istream &is, Person &p);
};

#endif

// 1) Lớp Person:
// - Tên (char*);
// - Tuổi (int);
// - Địa chỉ (char*).
// - Giới tính (bool): true – nam, false – nữ.