#ifndef PERSON_H
#define PERSON_H

#include<iostream>
using namespace std;

class Person
{
private:
    string name;
    int age;
    string passport;
public:
    Person();
    void setInfo(void);
    void ShowInfo(void);
    string getPassport(void);
};

#endif // PERSON_H
