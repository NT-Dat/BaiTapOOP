#include "customer.h"

Customer::Customer()
{

}

void Customer::setName(string name){
    this->name = name;
}

string Customer::getName(void){
    return this->name;
}

void Customer::setApartmentNumber(string number){
    this->apartmentNumber = number;
}

string Customer::getApartmentNumber(void){
    return this->apartmentNumber;
}

void Customer::setID(string ID){
    this->ID = ID;
}

string Customer::getID(void){
    return this->ID;
}

void Customer::setInfo(void){
    cout << "Enter name: "; cin.ignore(); getline(cin, this->name);
    cout << "Enter ApartmentNumber: "; getline(cin, this->apartmentNumber);
    cout << "Enter ID: "; getline(cin, this->ID);
}

void Customer::showInfo(void){
    cout << "Name: " << this->name << " - "
         << "ApartmentNumber: " << this->apartmentNumber << " - "
         << "ID: " << this->ID;
}
