#include "managervehicle.h"

managerVehicle::managerVehicle()
{

}

void managerVehicle::add(unique_ptr<Vehicle>& vehicle){
    if(this->managervehicle.count(vehicle->getID()) == 1){
        cout << "ID existed\n";
        int choice;
        cout << "Enter 0 ---> Menu\n";
        cin >> choice;
    }else{
        this->managervehicle[vehicle->getID()] = move(vehicle);
    }

}

void managerVehicle::deleteID(string ID){
    if(this->managervehicle.count(ID) != 0){
        this->managervehicle.erase(ID);
    }else{
        cout << "Not found\n";
    }
}

void managerVehicle::search(string ProductionCompany, string color){
    for(auto &x : this->managervehicle){
        if(x.second->getProductionCompany() == ProductionCompany && x.second->getColor() == color){
            x.second->showInfo();
        }else{
            cout << "Not found\n";
        }
    }
}

void managerVehicle::showAll(void){
    for(auto &x : this->managervehicle){
        x.second->showInfo();
    }
}
