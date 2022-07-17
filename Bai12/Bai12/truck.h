#ifndef TRUCK_H
#define TRUCK_H

#include "vehicle.h"

class Truck : public Vehicle
{
private:
    float vehicleLoad;
public:
    Truck();
    void setInfo(void);
    void showInfo(void);
};

#endif // TRUCK_H
