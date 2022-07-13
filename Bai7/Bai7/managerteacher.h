#ifndef MANAGERTEACHER_H
#define MANAGERTEACHER_H

#include "teacher.h"
#include<map>

class ManagerTeacher
{
    map<string, Teacher> managerTeacher;
public:
    ManagerTeacher();
    void addTeacher(void);
    void deleteTeacherByID(string);
    void showAllTeacher(void);
    void getRealSalaryByID(string);
};

#endif // MANAGERTEACHER_H
