#ifndef MANAGER_H
#define MANAGER_H

#include "department.h"
#include<map>
class manager
{
private:
    map<string,unique_ptr<Department>> managerUniversity;
public:
    manager();
    void addDepartment(void);
    void addStudent(string, unique_ptr<FormalUniversityStudent>&);
    int totalStudent_type_Department(string, string);
    void showBestStudent_Department(string);
    void showStudentinserviceByLink_Department(string, string);
    void showStudent_BestGPA(string);
    void show_sortStudent_Department(string);
};

#endif // MANAGER_H
