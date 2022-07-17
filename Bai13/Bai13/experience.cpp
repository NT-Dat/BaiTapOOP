#include "experience.h"

Experience::Experience()
{

}

void Experience::setInfo(void){
    Employee::setInfo();
    cout << "Enter ExpInYear:"; cin >> this->ExpInYear;
    cout << "Enter ProSkill:"; cin.ignore(); getline(cin, this->ProSkill);
}

void Experience::ShowInfo(void){
    Employee::ShowInfo();
    cout << "ExpInYear:" << this->ExpInYear << "--";
    cout << "ProSkill:" << this->ProSkill << endl;
}
