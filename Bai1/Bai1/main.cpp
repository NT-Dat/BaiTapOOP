#include "managerofficer.h"
using namespace std;

void Menu(ManagerOfficer &managerofficer){
    system("cls");
    cout << "**********   Application Manager Officer   *********\n";
    cout << "Enter 1: To insert officer\n";
    cout << "Enter 2: To search officer by name\n";
    cout << "Enter 3: To show information officers\n";
    cout << "Enter 0: To exit\n";
    int choice;
    string Name = "No name";
    do{
        cin >> choice;
        if(choice < 0 || choice > 3){
            cout << "No valid, retry:";
        }
    }while(choice < 0 || choice > 3);
    switch(choice){
    case 1:
        cout << "Enter a: to insert Enginner\n";
        cout << "Enter b: to insert Worker\n";
        cout << "Enter c: to insert Staff\n";
        Officer* officer;
        char type;
        cin >> type;
        switch(type){
        case 'a':
            officer = new Engineer;
            officer->SetInfo();
            managerofficer.addOfficer(officer);
            break;
        case 'b':
            officer = new Worker;
            officer->SetInfo();
            managerofficer.addOfficer(officer);
            break;
        case 'c':
            officer = new Staff;
            officer->SetInfo();
            managerofficer.addOfficer(officer);
            break;
        }
        break;
    case 2:
        cout << "Enter name of officers\n";
        cin.ignore();
        getline(cin,Name);
        managerofficer.shearchOfficerByName(Name);
        cout << "Enter 0 ---> Menu\n";
        cin >> choice;
        break;
    case 3:
        cout << "Information officers\n";
        managerofficer.ShowListInfoOfficer();
        cout << "Enter 0 ---> Menu\n";
        cin >> choice;
        break;
    case 0:
        exit(true);
    }
}

int main()
{
    ManagerOfficer managerofficer;
    while(true){
        Menu(managerofficer);
    }
    return 0;
}
