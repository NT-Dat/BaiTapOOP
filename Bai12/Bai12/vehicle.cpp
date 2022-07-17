#include "vehicle.h"

Vehicle::Vehicle()
{

}

Vehicle::~Vehicle()
{

}

void Vehicle::setInfo(void){
    cout << "Enter id:"; cin.ignore(); getline(cin, this->id);
    cout << "Enter ProductionCompany:"; getline(cin, this->productionCompany);
    cout << "Enter ProductionYear:"; cin >> this->productionYear;
    cout << "Enter price:"; cin >> this->price;
    cout << "Enter color:"; cin.ignore(); getline(cin, this->color);
}

void Vehicle::showInfo(void){
    cout << "ID:" << this->id << " - "
         << "ProductionCompany:" << this->productionCompany << " - "
         << "ProductionYear:" << this->productionYear << " - "
         << "Price:" << this->price << " - "
         << "Color:" << this->color << " - ";
}

string Vehicle::getID(void){
    return this->id;
}

string Vehicle::getProductionCompany(void){
    return this->productionCompany;
}

string Vehicle::getColor(void){
    return this->color;
}
