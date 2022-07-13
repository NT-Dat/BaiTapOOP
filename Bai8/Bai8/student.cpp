#include "student.h"

Student::Student()
{

}

void Student::setInfoStudent(void){
    cout << "Enter name: "; cin.ignore(); getline(cin, this->name);
    cout << "Enter age: "; cin >> this->age;
    cout << "Enter class: "; cin.ignore(); getline(cin, this->CLASS);
}

void Student::showInfoStudent(void){
    cout << "Name: " << this->name << " - "
         << "Age: " << this->age << " - "
         << "Class: " << this->CLASS << endl;
}
