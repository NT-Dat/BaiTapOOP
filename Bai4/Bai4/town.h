#ifndef TOWN_H
#define TOWN_H

#include "family.h"

class Town
{
private:
    vector<Family> family;
public:
    Town();
    void addFamily(void);
    void showTownInfo(void);
    bool checkPassport(Family&, int passport);
};

#endif // TOWN_H
