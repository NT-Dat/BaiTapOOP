#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include "person.h"
#include<memory>
using namespace std;

class Room
{
private:
    string category;
    int numberDay;
    Person person;
public:
    Room();
    void setRoom(void);
    void showRoom(void);
    string getPassportOfPerson(void);
    string getCategory(void);
    int getNumberDay(void);
    int getPrice(string);
};

#endif // ROOM_H
