#include <iostream>
#include "include/Person.h"
#include "include/Student.h"
#include "include/Lecturer.h"
#include "include/LopSinhHoat.h"
#include "include/mystring.h"
using namespace std;

void displayMenu(){
    cout << "\n========== QUAN LY LOP SINH HOAT ==========" << endl;
    cout << "1. Them lop" << endl;
    cout << "2. Xem danh sach lop" << endl;
    cout << "3. Them sinh vien" << endl;
    cout << "4. Cap nhat sinh vien" << endl;
    cout << "5. Cap nhat giang vien" << endl;
    cout << "6. Xoa sinh vien" << endl;
    cout << "7. Xem sinh vien" << endl;
    cout << "0. Thoat" << endl;
    cout << "Lua chon cua ban: ";
}

void displayClasses(LopSinhHoat* classes[], int classCount){
    cout << "\n=== DANH SACH LOP ===" << endl;
    for (int i = 0; i < classCount; i++){
        cout << i + 1 << ". " << classes[i]->getClassName()
             << " (" << classes[i]->getStudentCount() << " SV)" << endl;
    }
}

int main(){
    const int MAX_CLASSES = 10;
    LopSinhHoat *classes[MAX_CLASSES];
    int classCount = 0;
    int choice;

    do{
        displayMenu();
        cin >> choice;

        if (classCount == 0 && choice != 1){
            cout << "Chua co lop!" << endl;
            continue;
        }

        switch (choice){
        case 1: {
            if (classCount >= MAX_CLASSES){
                cout << "Da du lop!" << endl;
                break;
            }

            char className[100];
            cout << "Ten lop: ";
            cin.ignore();
            cin.getline(className, 100);

            Lecturer *advisor = new Lecturer();
            cout << "\n=== Nhap thong tin GVCN ===" << endl;
            cin >> *advisor;

            classes[classCount++] = new LopSinhHoat(className, advisor);
            cout << "Da them lop thanh cong!" << endl;
            break;
        }

        case 2: {
            displayClasses(classes, classCount);
            cout << "==============================" << endl;
            break;
        }

        case 3: {
            displayClasses(classes, classCount);
            cout << "Chon lop (1-" << classCount << "): ";
            int idx; cin >> idx;

            if (idx < 1 || idx > classCount){
                cout << "Lop khong hop le!" << endl;
                break;
            }

            cin >> *classes[idx - 1];
            break;
        }

        case 4:{
            displayClasses(classes, classCount);
            cout << "Chon lop (1-" << classCount << "): ";
            int idx; cin >> idx;

            if (idx < 1 || idx > classCount){
                cout << "Lop khong hop le!" << endl;
                break;
            }

            cout << "\n=== DANH SACH SINH VIEN ===" << endl;
            classes[idx - 1]->displayAllStudents();

            if (classes[idx - 1]->getStudentCount() == 0){
                cout << "Lop khong co sinh vien de cap nhat!" << endl;
                break;
            }

            cout << "\nChon STT sinh vien can cap nhat (1-" << classes[idx - 1]->getStudentCount() << "): ";
            int studentIdx; cin >> studentIdx;

            if (studentIdx < 1 || studentIdx > classes[idx - 1]->getStudentCount()){
                cout << "STT khong hop le!" << endl;
                break;
            }

            Student *found = classes[idx - 1]->operator[](studentIdx - 1);
            if (found){
                cout << "\n=== Thong tin hien tai ===" << endl;
                cout << *found << endl;
                cout << "\n=== Nhap thong tin moi ===" << endl;
                cin >> *found;
                cout << "Da cap nhat thanh cong!" << endl;
            }
            else cout << "Khong tim thay sinh vien!" << endl;

            break;
        }

        case 5:{
            displayClasses(classes, classCount);
            cout << "Chon lop (1-" << classCount << "): ";
            int idx; cin >> idx;

            if (idx < 1 || idx > classCount){
                cout << "Lop khong hop le!" << endl;
                break;
            }

            Lecturer* currentAdvisor = classes[idx - 1]->getAdvisor();
            if (currentAdvisor){
                cout << "\n=== Thong tin GVCN hien tai ===" << endl;
                cout << *currentAdvisor << endl;
                cout << "\n=== Nhap thong tin GVCN moi ===" << endl;
                cin >> *currentAdvisor;
                cout << "Da cap nhat GVCN thanh cong!" << endl;
            }
            else{
                cout << "Lop chua co GVCN!" << endl;
                Lecturer *advisor = new Lecturer();
                cout << "\n=== Nhap thong tin GVCN ===" << endl;
                cin >> *advisor;
                classes[idx - 1]->setAdvisor(advisor);
                cout << "Da them GVCN thanh cong!" << endl;
            }

            break;
        }

        case 6:{
            displayClasses(classes, classCount);
            cout << "Chon lop (1-" << classCount << "): ";
            int idx; cin >> idx;

            if (idx < 1 || idx > classCount){
                cout << "Lop khong hop le!" << endl;
                break;
            }

            cout << "\n=== DANH SACH SINH VIEN ===" << endl;
            classes[idx - 1]->displayAllStudents();

            if (classes[idx - 1]->getStudentCount() == 0){
                cout << "Lop khong co sinh vien de xoa!" << endl;
                break;
            }
            
            cout << "\nChon STT sinh vien can xoa (1-" << classes[idx - 1]->getStudentCount() << "): ";
            int studentIdx; cin >> studentIdx;

            if (studentIdx < 1 || studentIdx > classes[idx - 1]->getStudentCount()){
                cout << "STT khong hop le!" << endl;
                break;
            }

            classes[idx - 1]->removeStudent(studentIdx - 1);
            cout << "Da xoa sinh vien thanh cong!" << endl;
            break;
        }

        case 7:{
            displayClasses(classes, classCount);
            cout << "Chon lop (1-" << classCount << "): ";
            int idx; cin >> idx;
            cin.ignore();

            if (idx < 1 || idx > classCount) {
                cout << "Lop khong hop le!" << endl;
                break;
            }

            cout << "\n=== DANH SACH SINH VIEN ===" << endl;
            classes[idx - 1]->displayAllStudents();
            break;
        }

        case 0:
            cout << "Tam biet!" << endl;
            break;

        default:
            cout << "Lua chon khong hop le!" << endl;
        }
    } while (choice != 0);

    for (int i = 0; i < classCount; i++) delete classes[i];

    return 0;
}
