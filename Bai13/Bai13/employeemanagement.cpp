#include "employeemanagement.h"

EmployeeManagement::EmployeeManagement()
{

}

void EmployeeManagement::addEmployee(unique_ptr<Employee> employee){
    string id;
    do{
        cout << "Enter ID:"; cin.ignore(); getline(cin, id);
        employee->setID(id);
        if(this->employeeManagement.count(id) != 0){
            cout << "id already exist\n";
        }else{
            employee->setInfo();
        }
    }while(this->employeeManagement.count(id));
    this->employeeManagement[id] = move(employee);
}

void editEmployee(string);
void deleteEmployee(string);
void EmployeeManagement::searchEmployee(int type){
    for(auto &x : this->employeeManagement){
        if(x.second->getEmployee_type() == type){
            x.second->ShowInfo();
        }
    }
}
