#ifndef MOTORBIKE_H
#define MOTORBIKE_H

#include "vehicle.h"

class Motorbike : public Vehicle
{
private:
    int vehicleCapacity;
public:
    Motorbike();
    void setInfo(void);
    void showInfo(void);
};

#endif // MOTORBIKE_H
