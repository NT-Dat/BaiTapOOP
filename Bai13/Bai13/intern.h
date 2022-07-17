#ifndef INTERN_H
#define INTERN_H

#include "employee.h"

class Intern : public Employee
{
private:
    string Majors;
    int Semester;
    string University_name;
public:
    Intern();
    void setInfo(void);
    void ShowInfo(void);
};

#endif // INTERN_H
