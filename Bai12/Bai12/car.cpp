#include "car.h"

Car::Car()
{

}

void Car::setInfo(void){
    Vehicle::setInfo();
    cout << "Enter seatNumber:"; cin >> this->seatNumber;
    cout << "Enter engine:"; cin.ignore(); getline(cin, this->engine);
}

void Car::showInfo(void){
    Vehicle::showInfo();
    cout << "Seat number:" << this->seatNumber << " - "
         << "Engine:" << this->engine << endl;
}
