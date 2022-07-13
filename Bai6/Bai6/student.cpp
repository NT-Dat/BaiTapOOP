#include "student.h"

Student::Student()
{

}

void Student::setInfo(void){
    cin.ignore();cout << "Enter name: "; getline(cin, this->name);
    cout << "Enter age: "; cin >> this->age;
    cout << "Enter hometown: "; cin.ignore(); getline(cin, this->hometown);
    cout << "Enter class: "; cin >> this->classStudent;
}

void Student::showInfo(void){
    cout << "Name: " << this->name << " - "
         << "Age: " << this->age << " - "
         << "Home town: " << this->hometown << " - "
         << "Class: " << this->classStudent << endl;
}

int Student::getAge(void){
    return this->age;
}

string Student::getHometown(void){
    return this->hometown;
}
