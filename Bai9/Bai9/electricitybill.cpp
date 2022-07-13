#include "electricitybill.h"

ElectricityBill::ElectricityBill()
{

}

void ElectricityBill::setOldIndicator(int value){
    this->oldIndicator = value;
}

void ElectricityBill::setNewIndicator(int value){
    if(value < this->oldIndicator){
        cout << "NewIndicator < OldIndicator, re-enter\n";
    }
    this->NewIndicator = value;
}

int ElectricityBill::getOldIndicator(void){
    return this->oldIndicator;
}

int ElectricityBill::getNewIndicator(void){
    return this->NewIndicator;
}

int ElectricityBill::getPrice(void){
    return (this->NewIndicator - this->oldIndicator) * 5;
}

void ElectricityBill::setCustomer(void){
    this->customer.setInfo();
}

void ElectricityBill::setBill(void){
    this->setCustomer();
    int value;
    cout << "Enter OldIndicator: "; cin >> value; this->setOldIndicator(value);
    cout << "Enter NewIndicator:"; cin >> value; this->setNewIndicator(value);
}

void ElectricityBill::showBill(void){
    this->customer.showInfo();
    cout << "OldIndicator:" << this->getOldIndicator() << " - "
         << "NewIndicator:" << this->getNewIndicator() << " - "
         << "Price:" << this->getPrice() << endl;
}
