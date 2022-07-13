#include "hotel.h"

Hotel::Hotel()
{

}

void Hotel::showAll(void){
    for(auto it = this->hotel.begin(); it != this->hotel.end(); it++){
        (*it).second.showRoom();
    }
}

void Hotel::addPerson(void){
    Room room;
    room.setRoom();
    if(this->hotel.count(room.getPassportOfPerson()) != 0){
        cout << "Passport number already exists\n";
    }else{
        this->hotel[room.getPassportOfPerson()] = move(room);
    }
}

void Hotel::deletePerson(string passport){
    if(this->hotel.count(passport) != 0){
        this->hotel.erase(passport);
    }else{
        cout << "Not found\n";
    }
}

void Hotel::calculator(string passport){
    if(this->hotel.count(passport) != 0){
        cout<< "Total: " << this->hotel[passport].getNumberDay() * this->hotel[passport].getPrice(this->hotel[passport].getCategory())
            << "$" << endl;
    }else{
        cout << "Not found\n";
    }
}
