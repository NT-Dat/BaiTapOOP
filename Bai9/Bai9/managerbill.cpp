#include "managerbill.h"

ManagerBill::ManagerBill()
{

}

void ManagerBill::addBill(void){
    ElectricityBill bill;
    bill.setBill();
    this->managerBill.push_front(move(bill));
}

void ManagerBill::showAll(void){
    for(auto &x : this->managerBill){
        x.showBill();
    }
}
