#ifndef EXPERIENCE_H
#define EXPERIENCE_H

#include "Employee.h"

class Experience : public Employee
{
private:
    int ExpInYear;
    string ProSkill;
public:
    Experience();
    void setInfo(void);
    void showInfo(void);
};

#endif 
