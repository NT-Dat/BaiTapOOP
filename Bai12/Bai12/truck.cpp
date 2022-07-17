#include "truck.h"

Truck::Truck()
{

}

void Truck::setInfo(void){
    Vehicle::setInfo();
    cout << "Enter vehicleLoad:"; cin >> this->vehicleLoad;
}

void Truck::showInfo(void){
    Vehicle::showInfo();
    cout << "vehicleLoad:" << this->vehicleLoad << endl;
}
