#ifndef ELECTRICITYBILL_H
#define ELECTRICITYBILL_H

#include "customer.h"

class ElectricityBill
{
private:
    Customer customer;
    int oldIndicator;
    int NewIndicator;
    int price;
public:
    ElectricityBill();
    void setCustomer(void);
    void setOldIndicator(int);
    void setNewIndicator(int);
    int getOldIndicator(void);
    int getNewIndicator(void);
    int getPrice(void);
    void setBill(void);
    void showBill(void);
};

#endif // ELECTRICITYBILL_H
