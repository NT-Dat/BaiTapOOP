#ifndef CAR_H
#define CAR_H

#include "vehicle.h"

class Car : public Vehicle
{
private:
    int seatNumber;
    string engine;
public:
    Car();
    void setInfo(void);
    void showInfo(void);
};

#endif // CAR_H
