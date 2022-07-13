#include "town.h"

Town::Town()
{

}

void Town::addFamily(void){
    Family family; Person person;
    string address; int numberPerson;
    cout << "Enter address: "; cin.ignore(); getline(cin, address);
    family.setAddress(address);
    cout << "Enter number person: "; cin >> numberPerson;
    family.setNumberPerson(numberPerson);
    for(int i = 1; i <= numberPerson;){
        cout << "Enter person " << i << endl;
        person.setPersonInfo();
        if(this->checkPassport(family, person.getPassport()) == false){
            family.addPerson(person);
            i++;
        }else{
            cout << "Passport number already exists\n";
        }
    }
    this->family.push_back(move(family));
}

bool Town::checkPassport(Family &family, int passport){
    if(this->family.empty()){
        if(family.checkPassport(passport)){
            return true;
        }
    }else{
        for(int i = 0; i < this->family.size(); i++){
            if(this->family[i].checkPassport(passport)){
                return true;
            }
        }
    }
    return false;
}

void Town::showTownInfo(void){
    for(int i = 0; i < this->family.size(); i++){
        cout << "***** Family " << i + 1 << " *****\n";
        this->family[i].showFamilyInfo();
    }
}
