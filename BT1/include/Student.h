#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <iostream>
#include "mystring.h"
using namespace std;

class LopSinhHoat;

class Student : public Person
{
private:
    char *studentID;        // 10 ký tự (0-9), ký tự đầu không được là "0"
    LopSinhHoat *classInfo; // Thông tin lớp sinh hoạt
    double gpa4;            // Điểm trung bình (0 → 4)

public:
    Student();
    Student(const char *name, int age, const char *address, bool gender, const char *studentID, LopSinhHoat *classInfo, double gpa4);
    ~Student();

    char *getStudentID() const;
    LopSinhHoat *getClassInfo() const;
    double getGPA4() const;

    void setStudentID(const char *studentID);
    void setClassInfo(LopSinhHoat *classInfo);
    void setGPA4(double gpa4);

    bool isValidStudentID(const char *id) const;
    bool isValidGPA(double gpa) const;

    friend ostream &operator<<(ostream &os, const Student &s);
    friend istream &operator>>(istream &is, Student &s);
};

#endif

// 2) Lớp SinhVien: kế thừa từ lớp Person
// - Mã số sinh viên (char*): gồm 10 ký tự (0, … 9), ký tự đầu tiên không được bắt đầu bằng ký tự “0”;
// - Lớp (kiểu LopSinhHoat);
// - Điểm trung bình (double): có giá trị trong khoảng 0 → 4.