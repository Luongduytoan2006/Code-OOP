#include <iostream>
#include "../include/mystring.h"
#include "../include/Lecturer.h"
using namespace std;

Lecturer::Lecturer() : Person(){
    lecturerID = nullptr;
    rank = nullptr;
}

Lecturer::Lecturer(const char *name, int age, const char *address, bool gender, const char *lecturerID, const char *rank): Person(name, age, address, gender){
    if (lecturerID && isValidLecturerID(lecturerID)){
        this->lecturerID = new char[strlen(lecturerID) + 1];
        strcpy(this->lecturerID, lecturerID);
    }
    else this->lecturerID = nullptr;

    if (rank){
        this->rank = new char[strlen(rank) + 1];
        strcpy(this->rank, rank);
    }
    else this->rank = nullptr;
}

Lecturer::~Lecturer(){
    if (lecturerID) delete[] lecturerID;
    if (rank) delete[] rank;
}

char *Lecturer::getLecturerID() const{
    return lecturerID;
}

char *Lecturer::getRank() const{
    return rank;
}

void Lecturer::setLecturerID(const char *lecturerID){
    if (this->lecturerID) delete[] this->lecturerID;
    if (lecturerID && isValidLecturerID(lecturerID)){
        this->lecturerID = new char[strlen(lecturerID) + 1];
        strcpy(this->lecturerID, lecturerID);
    }
    else this->lecturerID = nullptr;
}

void Lecturer::setRank(const char *rank){
    if (this->rank) delete[] this->rank;
    if (rank){
        this->rank = new char[strlen(rank) + 1];
        strcpy(this->rank, rank);
    }
    else this->rank = nullptr;
}

char *Lecturer::generateLecturerID(const char *fullName) {
    if (!fullName)
        return nullptr;

    char *result = new char[256];
    strcpy(result, "102");
    int pos = 3;

    char nameCopy[256];
    strcpy(nameCopy, fullName);

    char *token = strtok(nameCopy, " ");
    char *lastName = nullptr;
    char initials[256] = "";
    int initialPos = 0;

    while (token != nullptr){
        if (lastName) initials[initialPos++] = toLower(lastName[0]);
        lastName = token;
        token = strtok(nullptr, " ");
    }
    initials[initialPos] = '\0';

    strcat(result, initials);
    for (int i = 0; lastName[i]; i++) result[pos++] = toLower(lastName[i]);
    result[pos] = '\0';

    return result;
}

bool Lecturer::isValidLecturerID(const char *id) const {
    if (!id || strlen(id) < 3) return false;
    
    return (id[0] == '1' && id[1] == '0' && id[2] == '2');
}

ostream &operator<<(ostream &os, const Lecturer &l){
    os << (Person &)l << ", Ma GV: " << (l.lecturerID ? l.lecturerID : "") << ", Cap bac: " << (l.rank ? l.rank : "");
    return os;
}

istream &operator>>(istream &is, Lecturer &l){
    is >> (Person &)l;

    char temp[256];
    cout << "Nhap cap bac (assistant/associate/full professor): ";
    is.ignore();
    is.getline(temp, 256);
    l.setRank(temp);

    return is;
}
