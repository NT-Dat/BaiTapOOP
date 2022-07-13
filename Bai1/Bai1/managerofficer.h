#ifndef MANAGEROFFICER_H
#define MANAGEROFFICER_H

#include "officer.h"
#include "worker.h"
#include "engineer.h"
#include "staff.h"
#include<vector>

class ManagerOfficer
{
private:
    vector<Officer*> officer;
public:
    ManagerOfficer();
    ~ManagerOfficer();
    void addOfficer(Officer*);
    void shearchOfficerByName(string);
    void ShowListInfoOfficer(void);
};

#endif // MANAGEROFFICER_H
