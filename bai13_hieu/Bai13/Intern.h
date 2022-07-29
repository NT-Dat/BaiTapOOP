#ifndef INTERN_H
#define INTERN_H

#include "Employee.h"

class Intern : public Employee
{
private:
    string Majors;
    int Semester;
    string University_name;
public:
    Intern();
    void setInfo(void);
    void showInfo(void);
};

#endif
