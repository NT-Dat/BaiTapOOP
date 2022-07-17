#ifndef EMPLOYEEMANAGEMENT_H
#define EMPLOYEEMANAGEMENT_H

#include "employee.h"
#include "experience.h"
#include "fresher.h"
#include "intern.h"
#include<map>
#include<memory>

class EmployeeManagement
{
private:
    map<string, unique_ptr<Employee>> employeeManagement;
public:
    EmployeeManagement();
    void addEmployee(unique_ptr<Employee>);
    void editEmployee(string);
    void deleteEmployee(string);
    void searchEmployee(int);
};

#endif // EMPLOYEEMANAGEMENT_H
