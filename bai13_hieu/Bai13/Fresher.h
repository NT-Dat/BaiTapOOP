#ifndef FRESHER_H
#define FRESHER_H

#include "Employee.h"

class Fresher : public Employee
{
private:
    int Graduation_date;
    string Graduation_rank;
    string Education;
public:
    Fresher();
    void setInfo();
    void showInfo();
};

#endif
