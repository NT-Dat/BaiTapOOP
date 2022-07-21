#include <iostream>
#include "manager.h"
using namespace std;

void Menu(manager &Manager){
    system("cls");
    cout << "**********   Application Manager *********\n";
    cout << "Enter 1: To insert department\n";
    cout << "Enter 2: To add student\n";
    cout << "Enter 3: To count student by type\n";
    cout << "Enter 4: To show best student\n";
    cout << "Enter 5: To show Studentinservice By Link\n";
    cout << "Enter 6: To show Student_BestGPA\n";
    cout << "Enter 7: To show_sortStudent\n";
    cout << "Enter 0: To exit\n";
    int choice;
    char type;
    string link;
    string nameDepartment;
    string student_type;
    unique_ptr<FormalUniversityStudent> student;
    do{
        cin >> choice;
        if(choice < 0 || choice > 7){
            cout << "No valid, retry:";
        }
    }while(choice < 0 || choice > 7);
    switch(choice){
    case 1:
        Manager.addDepartment();
        cout << "Enter 0 ---> Menu\n";
        cin >> choice;
        break;
    case 2:
        cout << "Enter a: to insert FormalUniversityStudent\n";
        cout << "Enter b: to insert StudentInService\n";
        cin >> type;
        switch(type){
        case 'a':
            student = make_unique<FormalUniversityStudent>();
            break;
        case 'b':
            student = make_unique<StudentInService>();
            break;
        }
        cout << "Enter name department:"; cin.ignore(); getline(cin, nameDepartment);
        Manager.addStudent(nameDepartment, student);
        cout << "Enter 0 ---> Menu\n";
        cin >> choice;
        break;
    case 3:
        cout << "Enter name department:"; cin.ignore(); getline(cin, nameDepartment);
        cout << "Enter a: to count FormalUniversityStudent\n";
        cout << "Enter b: to count StudentInService\n";
        cin >> type;
        switch(type){
        case 'a':
            student_type = "FormalUniversityStudent";
            break;
        case 'b':
            student_type = "StudentInService";
            break;
        }
        cout << Manager.totalStudent_type_Department(nameDepartment, student_type);
        cout << "Enter 0 ---> Menu\n";
        cin >> choice;
        break;
    case 4:
        cout << "Enter name department:"; cin.ignore(); getline(cin, nameDepartment);
        Manager.showBestStudent_Department(nameDepartment);
        cout << "Enter 0 ---> Menu\n";
        cin >> choice;
        break;
    case 5:
        cout << "Enter name department:"; cin.ignore(); getline(cin, nameDepartment);
        cout << "Enter link:"; getline(cin, link);
        Manager.showStudentinserviceByLink_Department(nameDepartment, link);
        cout << "Enter 0 ---> Menu\n";
        cin >> choice;
        break;
    case 6:
        cout << "Enter name department:"; cin.ignore(); getline(cin, nameDepartment);
        Manager.showStudent_BestGPA(nameDepartment);
        cout << "Enter 0 ---> Menu\n";
        cin >> choice;
        break;
    case 7:
        cout << "Enter name department:"; cin.ignore(); getline(cin, nameDepartment);
        Manager.show_sortStudent_Department(nameDepartment);
        cout << "Enter 0 ---> Menu\n";
        cin >> choice;
        break;
    default :
        exit(true);
    }
}


int main()
{
    manager Manager;
    while(true){
        Menu(Manager);
    }
    return 0;
}
