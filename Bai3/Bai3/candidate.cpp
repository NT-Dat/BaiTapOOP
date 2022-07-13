#include "candidate.h"

Candidate::Candidate(){}

Candidate::~Candidate(){}

string Candidate::getId(void){
    return this->id;
}

void Candidate::setInfo(void){
    cin.ignore(); cout << "Enter id: "; getline(cin, this->id);
    cout << "Enter name: "; getline(cin, this->name);
    cout << "Enter address: "; getline(cin, this->address);
    cout << "Enter priority: "; cin >> this->priority;
}

void Candidate::showInfo(void){
    cout << "id: " << this->id << " *** ";
    cout << "name: " << this->name << " *** ";
    cout << "address: " << this->address << " *** ";
    cout << "priority: " << this->priority << " *** ";
}
