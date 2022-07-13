#include "person.h"

Person::Person()
{

}

void Person::setInfo(void){
    cin.ignore(); cout << "Enter name: ";getline(cin, this->name);
    cout << "Enter age: "; cin >> this->age;
    cout << "Enter passport: "; cin.ignore(); getline(cin, this->passport);
}
void Person::ShowInfo(void){
    cout << "Name: " << this->name << " - "
         << "Age: " << this->age << " - "
         << "Passport: " << this->passport << endl;
}

string Person::getPassport(void){
    return this->passport;
}
