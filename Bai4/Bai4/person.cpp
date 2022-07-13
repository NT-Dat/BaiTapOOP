#include "person.h"

Person::Person()
{

}

void Person::setPersonInfo(void){
    cin.ignore();cout << "Enter name: "; getline(cin, this->name);
    cout << "Enter age: "; cin >> this->age;
    cin.ignore(); cout << "Enter job: "; getline(cin, this->job);
    cout << "Enter passport: "; cin >> this->passport;
}

void Person::showPersonInfo(void){
    cout << "name: " << this->name << " - "
         << "age: " << this->age << " - "
         << "job: " << this->job << " - "
         << "passport: " << this->passport << endl;
}

int Person::getPassport(void){
    return this->passport;
}
