#ifndef FAMILY_H
#define FAMILY_H

#include "person.h"
#include<vector>
#include<map>
#include<memory>

class Family
{
private:
    map<int, Person> person;
    string address;
    int numberPerson;
public:
    Family();
    void setNumberPerson(int);
    void setAddress(string);
    int getNumberPerson(void);
    string getAddress(void);
    void addPerson(Person);
    void showFamilyInfo(void);
    bool checkPassport(int);
};

#endif // FAMILY_H
