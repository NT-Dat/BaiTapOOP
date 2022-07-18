#include "intern.h"

Intern::Intern()
{

}

void Intern::setInfo(void){
    Employee::setInfo();
    cout << "Enter Majors:";cin.ignore(); getline(cin, this->Majors);
    cout << "Enter Semester:"; cin >> this->Semester;
    cout << "Enter University_name:"; cin.ignore(); getline(cin, this->University_name);
}

void Intern::ShowInfo(void){
    Employee::ShowInfo();
    cout << "Majors:" << this->Majors << "--";
    cout << "Semester:" << this->Semester << "--";
    cout << "University_name:" << this->University_name << endl;
}
