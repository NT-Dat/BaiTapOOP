#include "Intern.h"

Intern::Intern()
{

}

void Intern::setInfo(void){
    Employee::setInfo();
    cout << "Enter Majors:";
    cin.ignore(); 
    getline(cin, this->Majors);
    cout << "Enter Semester:"; 
    cin >> this->Semester;
    cout << "Enter University_name:"; 
    cin.ignore(); 
    getline(cin, this->University_name);
}

void Intern::showInfo(void){
    Employee::showInfo();
    cout << "Majors:" << this->Majors << endl;
    cout << "Semester:" << this->Semester << endl;
    cout << "University_name:" << this->University_name << endl;
}
