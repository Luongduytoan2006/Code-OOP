#include <iostream>
#include "../include/mystring.h"
#include "../include/Student.h"
#include "../include/LopSinhHoat.h"
using namespace std;

Student::Student() : Person(){
    studentID = nullptr;
    classInfo = nullptr;
    gpa4 = 0.0;
}

Student::Student(const char *name, int age, const char *address, bool gender,
                 const char *studentID, LopSinhHoat *classInfo, double gpa4)
    : Person(name, age, address, gender)
{
    if (studentID && isValidStudentID(studentID)){
        this->studentID = new char[strlen(studentID) + 1];
        strcpy(this->studentID, studentID);
    }
    else this->studentID = nullptr;

    this->classInfo = classInfo;
    this->gpa4 = isValidGPA(gpa4) ? gpa4 : 0.0;
}

Student::~Student(){
    delete[] studentID;
}

char *Student::getStudentID() const{
    return studentID;
}

LopSinhHoat *Student::getClassInfo() const{
    return classInfo;
}

double Student::getGPA4() const{
    return gpa4;
}

void Student::setStudentID(const char *studentID){
    if (this->studentID) delete[] this->studentID;
    if (studentID && isValidStudentID(studentID)){
        this->studentID = new char[strlen(studentID) + 1];
        strcpy(this->studentID, studentID);
    }
    else this->studentID = nullptr;
}

void Student::setClassInfo(LopSinhHoat *classInfo){
    this->classInfo = classInfo;
}

void Student::setGPA4(double gpa4){
    this->gpa4 = isValidGPA(gpa4) ? gpa4 : this->gpa4;
}

bool Student::isValidStudentID(const char *id) const{
    if (!id || strlen(id) != 10) return false;
    if (id[0] == '0') return false;
    for (int i = 0; i < 10; i++){
        if (id[i] < '0' || id[i] > '9') return false;
    }
    return true;
}

bool Student::isValidGPA(double gpa) const{
    return (gpa >= 0.0 && gpa <= 4.0);
}

ostream &operator<<(ostream &os, const Student &s){
    os << (Person &)s << ", MSSV: " << (s.studentID ? s.studentID : "")
       << ", GPA: " << s.gpa4;
    return os;
}

istream &operator>>(istream &is, Student &s){
    is >> (Person &)s;

    char temp[256];
    cout << "Nhap ma sinh vien (10 chu so, khong bat dau bang 0): ";
    is.ignore();
    is.getline(temp, 256);
    s.setStudentID(temp);

    cout << "Nhap diem GPA (0-4): ";
    is >> s.gpa4;

    return is;
}
