#include "managercard.h"

void Menu(ManagerCard &managerCard){
    system("cls");
    cout << "**********   Application Manager Card   *********\n";
    cout << "Enter 1: To add Card\n";
    cout << "Enter 2: To delete Card by Id\n";
    cout << "Enter 3: To show Card\n";
    cout << "Enter 0: To exit\n";
    int choice;
    string ID;
    do{
        cin >> choice;
        if(choice < 0 || choice > 3){
            cout << "No valid, retry:";
        }
    }while(choice < 0 || choice > 3);
    switch(choice){
    case 0:
        exit(true);
    case 1:
        cout << "Enter info\n";
        managerCard.addCard();
        cout << "Enter 0 ---> Menu\n";
        cin >> choice;
        break;
    case 2:
        cout << "Enter ID\n";
        cin >> ID;
        managerCard.deleteCard(ID);
        cout << "Enter 0 ---> Menu\n";
        cin >> choice;
        break;
    case 3:
        managerCard.showAll();
        cout << "Enter 0 ---> Menu\n";
        cin >> choice;
        break;
    }
}

int main()
{
    ManagerCard managerCard;
    while(true){
        Menu(managerCard);
    }
    return 0;
}

