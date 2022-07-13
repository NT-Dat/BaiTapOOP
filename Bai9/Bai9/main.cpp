#include "managerbill.h"

void Menu(ManagerBill &managerBill){
    system("cls");
    cout << "**********   Application Manager Bill   *********\n";
    cout << "Enter 1: To add Bill\n";
    cout << "Enter 2: To show all\n";
    cout << "Enter 0: To exit\n";
    int choice;
    string ID;
    do{
        cin >> choice;
        if(choice < 0 || choice > 2){
            cout << "No valid, retry:";
        }
    }while(choice < 0 || choice > 2);
    switch(choice){
    case 0:
        exit(true);
    case 1:
        cout << "Enter info\n";
        managerBill.addBill();
        cout << "Enter 0 ---> Menu\n";
        cin >> choice;
        break;
    case 2:
        managerBill.showAll();
        cout << "Enter 0 ---> Menu\n";
        cin >> choice;
        break;
    }
}

int main()
{
    ManagerBill managerBill;
    while(true){
        Menu(managerBill);
    }
    return 0;
}

