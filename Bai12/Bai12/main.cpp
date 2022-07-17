#include "managervehicle.h"

void Menu(managerVehicle &managervehicle){
    system("cls");
    cout << "**********   Application Manager Vehicle   *********\n";
    cout << "Enter 1: To insert Vehicle\n";
    cout << "Enter 2: To show Vehicle information\n";
    cout << "Enter 3: To delete by ID\n";
    cout << "Enter 4: To search by ProductionCompany and color\n";
    cout << "Enter 0: To exit\n";
    int choice;
    char type;
    string id;
    string ProductionCompany, color;
    do{
        cin >> choice;
        if(choice < 0 || choice > 4){
            cout << "No valid, retry:";
        }
    }while(choice < 0 || choice > 4);
    switch(choice){
    case 1:
        cout << "Enter a: to insert car \n";
        cout << "Enter b: to insert motorbike \n";
        cout << "Enter c: to insert truck \n";
        cin >> type;
        switch(type){
        case 'a':
        {
            unique_ptr<Vehicle> car(new Car);
            car->setInfo();
            managervehicle.add(car);
        }
            break;
        case 'b':
        {
            unique_ptr<Vehicle> motorbike(new Motorbike);
            motorbike->setInfo();
            managervehicle.add(motorbike);
        }
            break;
        case 'c':
            unique_ptr<Vehicle> truck(new Truck);
            truck->setInfo();
            managervehicle.add(truck);
            break;
        }
        break;
    case 2:
        cout << "Vehicle information\n";
        managervehicle.showAll();
        cout << "Enter 0 ---> Menu\n";
        cin >> choice;
        break;
    case 3:
        cout << "Enter ID\n";
        cin >> id;
        managervehicle.deleteID(id);
        cout << "Enter 0 ---> Menu\n";
        cin >> choice;
        break;
    case 4:
        cout << "Enter ProductionCompany\n";
        cin.ignore(); getline(cin, ProductionCompany);
        cout << "Enter color\n";
        getline(cin, color);
        managervehicle.search(ProductionCompany, color);
        cout << "Enter 0 ---> Menu\n";
        cin >> choice;
        break;
   default :
        exit(true);
    }
}

int main()
{
    managerVehicle managervehicle;
    while(true){
        Menu(managervehicle);
    }
    return 0;
}
