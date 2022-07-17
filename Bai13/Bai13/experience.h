#ifndef EXPERIENCE_H
#define EXPERIENCE_H

#include "employee.h"

class Experience : public Employee
{
private:
    int ExpInYear;
    string ProSkill;
public:
    Experience();
    void setInfo(void);
    void ShowInfo(void);
};

#endif // EXPERIENCE_H
