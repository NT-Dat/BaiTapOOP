#ifndef MANAGERVEHICLE_H
#define MANAGERVEHICLE_H

#include<iostream>
#include<memory>
#include<map>
#include "vehicle.h"
#include "car.h"
#include "motorbike.h"
#include "truck.h"

using namespace std;

class managerVehicle
{
private:
    map<string, unique_ptr<Vehicle>> managervehicle;
public:
    managerVehicle();
    void add(unique_ptr<Vehicle>&);
    void deleteID(string);
    void search(string, string);
    void showAll(void);
};

#endif // MANAGERVEHICLE_H
