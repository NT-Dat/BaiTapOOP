#ifndef HOTEL_H
#define HOTEL_H

#include "room.h"
#include<map>
#include<memory>

class Hotel
{
private:
    map<string, Room> hotel;
public:
    Hotel();
    void showAll(void);
    void addPerson(void);
    void deletePerson(string);
    void calculator(string);
};

#endif // HOTEL_H
