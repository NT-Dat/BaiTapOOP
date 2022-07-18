#include "employeemanagement.h"

EmployeeManagement::EmployeeManagement()
{

}

void EmployeeManagement::addEmployee(unique_ptr<Employee> &employee){
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

void EmployeeManagement::editEmployee(string ID){
    if(this->employeeManagement.count(ID) != 0){
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
                this->employeeManagement[ID]->setFullName();
                cout << "Enter 0 ---> Menu\n";
                cin >> choice;
                break;
            case 2:
                this->employeeManagement[ID]->setBirthDay();
                cout << "Enter 0 ---> Menu\n";
                cin >> choice;
                break;
            case 3:
                this->employeeManagement[ID]->setPhone();
                cout << "Enter 0 ---> Menu\n";
                cin >> choice;
                break;
            case 4:
                this->employeeManagement[ID]->setEmail();
                cout << "Enter 0 ---> Menu\n";
                cin >> choice;
                break;
            default :
                return;
            }
        }
    }else{
        cout << "Not found\n";
    }
}

void EmployeeManagement::deleteEmployee(string ID){
    if(this->employeeManagement.count(ID) != 0){
            this->employeeManagement.erase(ID);
        }else{
            cout << "Not found\n";
        }
}

void EmployeeManagement::searchEmployee(int type){
    for(auto &x : this->employeeManagement){
        if(x.second->getEmployee_type() == type){
            x.second->ShowInfo();
        }
    }
}
