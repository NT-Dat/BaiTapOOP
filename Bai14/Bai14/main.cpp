#include <iostream>
#include "managerstudent.h"
using namespace std;

void Menu(managerStudent &manager, int number){
    system("cls");
    cout << "**********   Application Manager *********\n";
    cout << "Enter 1: To insert Student\n";
    cout << "Enter 2: To show all\n";
    cout << "Enter 3: To show pass\n";
    cout << "Enter 0: To exit\n";
    int choice;
    char type;
    string id;
    int Employee_type;
    unique_ptr<Student> student;
    do{
        cin >> choice;
        if(choice < 0 || choice > 3){
            cout << "No valid, retry:";
        }
    }while(choice < 0 || choice > 3);
    switch(choice){
    case 1:
        cout << "Enter a: to insert GoodStudent\n";
        cout << "Enter b: to insert NormalStudent\n";
        cin >> type;
        switch(type){
        case 'a':
            student = make_unique<GoodStudent>();
            break;
        case 'b':
            student = make_unique<NormalStudent>();
            break;
        }
        manager.add(student);
        break;
    case 2:
        manager.showAll();
        cout << "Enter 0 ---> Menu\n";
        cin >> choice;
        break;
    case 3:
        manager.showPass(number);
        cout << "Enter 0 ---> Menu\n";
        cin >> choice;
        break;
    default :
        exit(true);
    }
}


int main()
{
    managerStudent manager;
    int number;
    cout << "Enter recruit number:";
    cin >> number;
    while(true){
        Menu(manager, number);
    }
    return 0;
}
