#include "managerofficer.h"

ManagerOfficer::ManagerOfficer()
{

}

ManagerOfficer::~ManagerOfficer(){
    for(auto x : officer){
        delete x;
    }
    officer.clear();
}

void ManagerOfficer::addOfficer(Officer* officer){
    this->officer.push_back(officer);
}

void ManagerOfficer::shearchOfficerByName(string name){
    for(auto x : officer){
        if(x->getName() == name){
            x->ShowInfo();
        }
    }
}

void ManagerOfficer::ShowListInfoOfficer(){
    for(auto x : officer){
        x->ShowInfo();
    }
}
