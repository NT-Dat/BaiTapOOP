#include "family.h"

Family::Family()
{

}

void Family::setAddress(string address){
    this->address = address;
}

void Family::setNumberPerson(int number){
    this->numberPerson = number;
}

int Family::getNumberPerson(void){
    return this->numberPerson;
}

string Family::getAddress(void){
    return this->address;
}

void Family::addPerson(Person person){
    this->person[person.getPassport()] = move(person);
}

bool Family::checkPassport(int passport){
    if(this->person.count(passport) != 0){
        return true;
    }
    return false;
}

void Family::showFamilyInfo(void){
    cout << "Address: " << this->address << " - "
         << "NumberPerson: " << this->getNumberPerson() << endl;
    for(auto &x : this->person){
        x.second.showPersonInfo();
    }
}
