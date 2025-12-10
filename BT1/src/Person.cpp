#include <iostream>
#include "../include/mystring.h"
#include "../include/Person.h"
using namespace std;

Person::Person(){
    name = nullptr;
    age = -1;
    address = nullptr;
    gender = true;
}

Person::Person(const char *name, int age, const char *address, bool gender){
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);

    this->age = age;
    this->address = new char[strlen(address) + 1];
    strcpy(this->address, address);
    this->gender = gender;
}

Person::~Person(){
    delete[] name;
    delete[] address;
}

char *Person::getName() const{
    return name;
}

int Person::getAge() const{
    return age;
}

char *Person::getAddress() const{
    return address;
}

bool Person::getGender() const{
    return gender;
}

void Person::setName(const char *name){
    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

void Person::setAge(int age){
    this->age = age;
}

void Person::setAddress(const char *address){
    delete[] this->address;
    this->address = new char[strlen(address) + 1];
    strcpy(this->address, address);
}

void Person::setGender(bool gender){
    this->gender = gender;
}

ostream &operator<<(ostream &os, const Person &p){
    os << "Ten: " << (p.name ? p.name : "") 
       << ", Tuoi: " << p.age
       << ", Dia chi: " << (p.address ? p.address : "")
       << ", Gioi tinh: " << (p.gender ? "Nam" : "Nu");
    return os;
}

istream &operator>>(istream &is, Person &p){
    char temp[256];
    cout << "Nhap ten: ";
    is.ignore();
    is.getline(temp, 256);
    p.setName(temp);

    cout << "Nhap tuoi: ";
    is >> p.age;

    cout << "Nhap dia chi: ";
    is.ignore();
    is.getline(temp, 256);
    p.setAddress(temp);

    cout << "Nhap gioi tinh (1-Nam, 0-Nu): ";
    int g;
    is >> g;
    p.gender = g;

    return is;
}
