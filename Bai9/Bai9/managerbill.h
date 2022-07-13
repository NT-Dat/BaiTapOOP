#ifndef MANAGERBILL_H
#define MANAGERBILL_H

#include "electricitybill.h"
#include<list>

class ManagerBill
{
private:
    list<ElectricityBill> managerBill;
public:
    ManagerBill();
    void addBill(void);
    void showAll(void);
};

#endif // MANAGERBILL_H
