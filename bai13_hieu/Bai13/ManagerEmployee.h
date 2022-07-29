#ifndef MANAGEREMPLOYEE_H
#define MANAGEREMPLOYEE_H

#include "Fresher.h"
#include "Intern.h"
#include "Experience.h"
#include <map>
#include <memory>

enum option 
{
    Add = 1, 
    Edit, 
    Delete,
    Search
    
    
};
class EmployeeManagement
{
    private:
    map<string, unique_ptr<Employee>> employeeManagement;
public:
    EmployeeManagement();
    void addEmployee(unique_ptr<Employee>& );
    void editEmployee(string);
    void deleteEmployee(string);
    void searchEmployee(string);
};

#endif

