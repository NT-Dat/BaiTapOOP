#include "ManagerEmployee.h"

EmployeeManagement:: EmployeeManagement()
{
    
}

void EmployeeManagement:: addEmployee (unique_ptr<Employee> &employee)
{
    string id;
    do{
        cout << "Enter id:"; 
        cin.ignore(); 
        getline(cin, id);
        employee->setId(id);
        if(this->employeeManagement.count(id) != 0)
        {
            cout << "id already exist\n";
        }
        else
        {
            employee->setInfo();
        }
    }while(this->employeeManagement.count(id));
    this->employeeManagement[id] = move(employee);
}

void EmployeeManagement::editEmployee(string id)
{
    if(this->employeeManagement.count(id) != 0){
        while(1){
            system("cls");
            cout << "Enter 1: To edit FullName\n";
            cout << "Enter 2: To edit BirthDay\n";
            cout << "Enter 3: To edit Phone\n";
            cout << "Enter 4: To edit Email\n";
            cout << "Enter 0: To exit\n";
            int choice;
            do{
                cin >> choice;
                if(choice < 0 || choice > 4){
                    cout << "No valid, retry:";
                }
            }while(choice < 0 || choice > 4);
            switch(choice){
            case 1:
                this->employeeManagement[id]->setName();
                cout << "Enter 0 ---> Menu\n";
                cin >> choice;
                break;
            case 2:
                this->employeeManagement[id]->setBirth();
                cout << "Enter 0 ---> Menu\n";
                cin >> choice;
                break;
            case 3:
                this->employeeManagement[id]->setPhone();
                cout << "Enter 0 ---> Menu\n";
                cin >> choice;
                break;
            case 4:
                this->employeeManagement[id]->setEmail();
                cout << "Enter 0 ---> Menu\n";
                cin >> choice;
                break;
            default :
                return;
            }
        }
    }else
    {
        cout << "Not found\n";
    }
}

void EmployeeManagement::deleteEmployee(string id){
    if(this->employeeManagement.count(id) != 0){
            this->employeeManagement.erase(id);
        }else{
            cout << "Not found\n";
        }
}

void EmployeeManagement::searchEmployee(string type){
    for(auto &x : this->employeeManagement){
        if(x.second->getEmployeeType() == type){
            x.second->showInfo();
        }
    }
}
