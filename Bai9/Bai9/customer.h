#ifndef CUSTOMER_H
#define CUSTOMER_H

#include<iostream>
using namespace std;

class Customer
{
private:
    string name;
    string apartmentNumber;
    string ID;
public:
    Customer();
    void setName(string);
    string getName(void);
    void setApartmentNumber(string);
    string getApartmentNumber(void);
    void setID(string);
    string getID(void);
    void setInfo(void);
    void showInfo(void);
};

#endif // CUSTOMER_H
