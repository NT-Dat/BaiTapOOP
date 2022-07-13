#include "hotel.h"

void Menu(Hotel &hotel){
    system("cls");
    cout << "**********   Application Manager Hotel   *********\n";
    cout << "Enter 1: To add person\n";
    cout << "Enter 2: To remove person by passport\n";
    cout << "Enter 3: To show all\n";
    cout << "Enter 4: To calculate by passport\n";
    cout << "Enter 0: To exit\n";
    int choice;
    string category;
    string passport;
    string Name = "No name";
    do{
        cin >> choice;
        if(choice < 0 || choice > 4){
            cout << "No valid, retry:";
        }
    }while(choice < 0 || choice > 4);
    switch(choice){
    case 1:
        cout << "Enter info\n";
        hotel.addPerson();
        cout << "Enter 0 ---> Menu\n";
        cin >> choice;
        break;
    case 2:
        cout << "Enter passport\n";
        cin >> passport;
        hotel.deletePerson(passport);
        break;
    case 3:
        cout << "All Information\n";
        hotel.showAll();
        cout << "Enter 0 ---> Menu\n";
        cin >> choice;
        break;
    case 4:
        cout << "Enter passport\n";
        cin >> passport;
        hotel.calculator(passport);
        cout << "Enter 0 ---> Menu\n";
        cin >> choice;
        break;
    default :
        exit(true);
    }
}

int main()
{
    Hotel hotel;
    while(true){
        Menu(hotel);
    }
    return 0;
}

