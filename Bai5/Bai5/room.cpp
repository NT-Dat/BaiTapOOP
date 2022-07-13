#include "room.h"

Room::Room()
{

}

void Room::setRoom(void){
    this->person.setInfo();
    cout << "Enter category: RoomA or RoomB or RoomC--->";
    getline(cin, this->category);
    cout << "Enter number day: ";
    cin >> this->numberDay;
}
void Room::showRoom(void){
    cout << "Category: " << this->category << " - "
         << "Number day: " << this->numberDay << " - ";
    this->person.ShowInfo();
}

string Room::getPassportOfPerson(void){
    return this->person.getPassport();
}

string Room::getCategory(void){
    return this->category;
}

int Room::getNumberDay(void){
    return this->numberDay;
}

int Room::getPrice(string category){
    if(category == "RoomA"){
        return 500;
    }else if(category == "RoomB"){
        return 300;
    }else if(category == "RoomC"){
        return 100;
    }
    return 0;
}
