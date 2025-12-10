#include <fstream>
#include <iostream>
#include "../include/LopSinhHoat.h"
#include "../include/mystring.h"
using namespace std;

LopSinhHoat::LopSinhHoat(){
    className = nullptr;
    students = nullptr;
    advisor = nullptr;
    studentCount = 0;
    maxStudents = 0;
}

// Constructor tham số
LopSinhHoat::LopSinhHoat(const char* className, Lecturer* advisor, int maxStudents){
    if(className){
        this->className = new char[strlen(className) + 1];
        strcpy(this->className, className);
    }
    else this->className = nullptr;

    this->advisor = advisor;
    this->maxStudents = maxStudents;
    this->studentCount = 0;

    if(maxStudents > 0){
        students = new Student*[maxStudents];
        for(int i = 0; i < maxStudents; i++) students[i] = nullptr;
    }
    else students = nullptr;
}

// Destructor
LopSinhHoat::~LopSinhHoat(){
    if(className) delete[] className;

    if(students){
        for(int i = 0; i < studentCount; i++)
            if(students[i]) delete students[i];
        delete[] students;
    }
}

// Getters
char* LopSinhHoat::getClassName() const{
    return className;
}

Student** LopSinhHoat::getStudents() const{
    return students;
}

Lecturer* LopSinhHoat::getAdvisor() const{
    return advisor;
}

int LopSinhHoat::getStudentCount() const{
    return studentCount;
}

int LopSinhHoat::getMaxStudents() const{
    return maxStudents;
}

// Setters
void LopSinhHoat::setClassName(const char* className){
    if(this->className) delete[] this->className;
    if(className){
        this->className = new char[strlen(className) + 1];
        strcpy(this->className, className);
    }
    else this->className = nullptr;
}

void LopSinhHoat::setAdvisor(Lecturer* advisor){
    this->advisor = advisor;
}

// Thêm sinh viên vào lớp - sinh viên được tạo ngay trong lớp
void LopSinhHoat::addStudent(const char* name, int age, const char* address, bool gender, const char* studentID, double gpa4){
    if(studentCount >= maxStudents){
        cout << "Lop da day, khong the them sinh vien!" << endl;
        return;
    }

    Student* newStudent = new Student(name, age, address, gender, studentID, this, gpa4);
    students[studentCount] = newStudent;
    studentCount++;

    cout << "Da them sinh vien " << name << " vao lop " << className << endl;
}

void LopSinhHoat::removeStudent(int index){
    if(index < 0 || index >= studentCount){
        cout << "STT khong hop le!" << endl;
        return;
    }

    cout << "Dang xoa sinh vien: " << students[index]->getName() << " (MSSV: " << students[index]->getStudentID() << ")" << endl;
    
    delete students[index];
    for(int i = index; i < studentCount - 1; i++) students[i] = students[i + 1];
    
    students[studentCount - 1] = nullptr;
    studentCount--;
}

void LopSinhHoat::displayAllStudents() const{
    cout << "\n===== DANH SACH SINH VIEN LOP " << (className ? className : "") << " =====" << endl;
    cout << "Giao vien chu nhiem: " << (advisor ? advisor->getName() : "Chua co") << endl;
    cout << "Si so: " << studentCount << "/" << maxStudents << endl;
    cout << "-------------------------------------------------------" << endl;

    if(studentCount == 0) cout << "Lop chua co sinh vien nao!" << endl;
    else for(int i = 0; i < studentCount; i++) cout << (i + 1) << ". " << *students[i] << endl;
    cout << "=======================================================" << endl;
}

Student* LopSinhHoat::operator[](int index) const{
    if(index >= 0 && index < studentCount) return students[index];
    else return nullptr;
}

ostream& operator<<(ostream& os, const LopSinhHoat& lsh){
    os << "Lop: " << (lsh.className ? lsh.className : "")
       << ", GVCN: " << (lsh.advisor ? lsh.advisor->getName() : "Chua co") 
       << ", Si so: " << lsh.studentCount 
       << "/" << lsh.maxStudents;
    return os;
}

// Operator >>
// Format: Ten|Tuoi|DiaChi|GioiTinh|MSSV|GPA
istream& operator>>(istream& is, LopSinhHoat& lsh){
    char buffer[512];

    cout << "Nhap thong tin sinh vien (su dung dau | de phan cach):" << endl;
    cout << "Format: Ten|Tuoi|DiaChi|GioiTinh(0/1)|MSSV|GPA" << endl;
    cout << "Nhap: ";
    is.ignore();
    is.getline(buffer, 512);

    // Parse thong tin sinh vien
    char* token = strtok(buffer, "|");
    if(!token) return is;

    char name[256];
    strcpy(name, token);
    
    token = strtok(nullptr, "|");
    int age = token ? atoi(token) : 0;
    
    token = strtok(nullptr, "|");
    char address[256];
    strcpy(address, token ? token : "");
    
    token = strtok(nullptr, "|");
    bool gender = token ? (atoi(token) != 0) : true;
    
    token = strtok(nullptr, "|");
    char studentID[256];
    strcpy(studentID, token ? token : "");
    
    token = strtok(nullptr, "|");
    double gpa4 = token ? atof(token) : 0.0;

    lsh.addStudent(name, age, address, gender, studentID, gpa4);

    return is;
}
