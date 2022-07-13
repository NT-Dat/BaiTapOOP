#include "managerteacher.h"

void Menu(ManagerTeacher &managerTeacher){
    system("cls");
    cout << "**********   Application Manager Teacher   *********\n";
    cout << "Enter 1: To add Teacher\n";
    cout << "Enter 2: To delete Teacher by Id\n";
    cout << "Enter 3: To show teacher\n";
    cout << "Enter 4: To get real salary by ID\n";
    cout << "Enter 0: To exit\n";
    int choice;
    string ID;
    do{
        cin >> choice;
        if(choice < 0 || choice > 4){
            cout << "No valid, retry:";
        }
    }while(choice < 0 || choice > 4);
    switch(choice){
    case 0:
        exit(true);
    case 1:
        cout << "Enter info\n";
        managerTeacher.addTeacher();
        cout << "Enter 0 ---> Menu\n";
        cin >> choice;
        break;
    case 2:
        cout << "Enter ID\n";
        cin >> ID;
        managerTeacher.deleteTeacherByID(ID);
        cout << "Enter 0 ---> Menu\n";
        cin >> choice;
        break;
    case 3:
        managerTeacher.showAllTeacher();
        cout << "Enter 0 ---> Menu\n";
        cin >> choice;
        break;
    case 4:
        cout << "Enter ID\n";
        cin >> ID;
        managerTeacher.getRealSalaryByID(ID);
        cout << "Enter 0 ---> Menu\n";
        cin >> choice;
        break;
    }
}

int main()
{
    ManagerTeacher managerTeacher;
    while(true){
        Menu(managerTeacher);
    }
    return 0;
}

