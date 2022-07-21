#include "employeemanagement.h"

void Menu(EmployeeManagement &employeeManagement){
    system("cls");
    cout << "**********   Application Manager Employee   *********\n";
    cout << "Enter 1: To insert Employee\n";
    cout << "Enter 2: To edit Employee information\n";
    cout << "Enter 3: To delete by ID\n";
    cout << "Enter 4: To search by type\n";
    cout << "Enter 0: To exit\n";
    int choice;
    char type;
    string id;
    int Employee_type;
    unique_ptr<Employee> employee;
    do{
        cin >> choice;
        if(choice < 0 || choice > 4){
            cout << "No valid, retry:";
        }
    }while(choice < 0 || choice > 4);
    switch(choice){
    case 1:
        cout << "Enter a: to insert Experience  \n";
        cout << "Enter b: to insert Fresher  \n";
        cout << "Enter c: to insert Intern  \n";
        cin >> type;
        switch(type){
        case 'a':
            employee = make_unique<Experience>();
            break;
        case 'b':
            employee = make_unique<Fresher>();
            break;
        case 'c':
            employee = make_unique<Intern>();
            break;
        }
        employeeManagement.addEmployee(employee);
        break;
    case 2:
        cout << "Enter ID\n";
        cin >> id;
        employeeManagement.editEmployee(id);
        cout << "Enter 0 ---> Menu\n";
        cin >> choice;
        break;
    case 3:
        cout << "Enter ID\n";
        cin >> id;
        employeeManagement.deleteEmployee(id);
        cout << "Enter 0 ---> Menu\n";
        cin >> choice;
        break;
    case 4:
        cout << "Employee_type:";
        cin >> Employee_type;
        employeeManagement.searchEmployee(Employee_type);
        cout << "Enter 0 ---> Menu\n";
        cin >> choice;
        break;
   default :
        exit(true);
    }
}

int main()
{
    EmployeeManagement employeeManagement;
    while(true){
        Menu(employeeManagement);
    }
    return 0;
}
