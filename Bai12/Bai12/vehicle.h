#ifndef VEHICLE_H
#define VEHICLE_H

#include<iostream>
using namespace std;

class Vehicle
{
private:
    string id;
    string productionCompany;
    int productionYear;
    float price;
    string color;
public:
    Vehicle();
    virtual ~Vehicle();
    virtual void setInfo(void);
    virtual void showInfo(void);
    string getID(void);
    string getProductionCompany(void);
    string getColor(void);
};

#endif // VEHICLE_H
