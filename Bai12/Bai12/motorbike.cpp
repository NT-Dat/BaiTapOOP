#include "motorbike.h"

Motorbike::Motorbike()
{

}

void Motorbike::setInfo(void){
    Vehicle::setInfo();
    cout << "Enter vehicleCapacity:"; cin >> this->vehicleCapacity;
}

void Motorbike::showInfo(void){
    Vehicle::showInfo();
    cout << "vehicleCapacity:" << this->vehicleCapacity << endl;
}
