#ifndef LOPSINHHOAT_H
#define LOPSINHHOAT_H

#include "Student.h"
#include "Lecturer.h"
#include<iostream>
#include "mystring.h"
using namespace std;

class LopSinhHoat {
private:
    char* className;            // Tên lớp sinh hoạt
    Student** students;         // Danh sách sinh viên
    Lecturer* advisor;          // Giáo viên chủ nhiệm
    int studentCount;           // Số lượng sinh viên hiện tại
    int maxStudents;            // Sức chứa tối đa

public:
    LopSinhHoat();
    LopSinhHoat(const char* className, Lecturer* advisor, int maxStudents = 50);
    ~LopSinhHoat();
    
    char* getClassName() const;
    Student** getStudents() const;
    Lecturer* getAdvisor() const;
    int getStudentCount() const;
    int getMaxStudents() const;
    
    void setClassName(const char* className);
    void setAdvisor(Lecturer* advisor);
    
    void addStudent(const char* name, int age, const char* address, bool gender, const char* studentID, double gpa4);
    void removeStudent(int index);
    Student* findStudent(const char* studentID) const;
    void displayAllStudents() const;
    

    Student* operator[](int index) const;
    friend ostream& operator<<(ostream& os, const LopSinhHoat& lsh);
    friend istream& operator>>(istream& is, LopSinhHoat& lsh);
};

#endif


// 4) Lớp LopSinhHoat:
// - Tên lớp sinh hoạt (char*), ví dụ: 16T1, 16T2, …;
// - Danh sách các đối tượng sinh viên (sử dụng con trỏ trỏ đến mảng đối tượng);
// - Giáo viên chủ nhiệm (kiểu Lecturer);
// - Sĩ số sinh viên (int): số đối tượng sinh viên trong lớp (lưu ý cập nhật theo số đối tượng sinh viên hiện tại).
// - Các chức năng quản lý ứng dụng sẽ viết trong lớp này.
// - Đa năng hóa toán tử nhập xuất, toán tử truy cập [] và toán tử gán (=) cho lớp