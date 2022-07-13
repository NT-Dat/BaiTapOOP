#include "teacher.h"

Teacher::Teacher()
{

}

void Teacher::setInfo(void){
    cout << "Enter name: "; cin.ignore(); getline(cin, this->name);
    cout << "Enter age: "; cin >> this->age;
    cout << "Enter home town: "; cin.ignore(); getline(cin, this->hometown);
    cout << "Enter id: "; getline(cin, this->id);
    cout << "Enter salary: "; cin >> this->salary;
}

void Teacher::showInfo(void){
    cout << "Name: " << this->name << " - "
         << "Age: " << this->age << " - "
         << "Home town: " << this->hometown << " - "
         << "Id: " << this->id << " - "
         << "Salary: " << this->salary << " - "
         << "Bonus: " << this->bonus << " - "
         << "Penaty: " << this->penaty << " - "
         << "Real salary: " << this->getRealSalary() << endl;
}

string Teacher::getId(void){
    return this->id;
}

double Teacher::getRealSalary(void){
    return this->salary + this->bonus - this->penaty;
}

void Teacher::setBonus_Penaty(double bonus, double penaty){
    this->bonus = bonus;
    this->penaty = penaty;
}

