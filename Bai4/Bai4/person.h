#ifndef PERSON_H
#define PERSON_H

#include<iostream>

using namespace std;
class Person
{
private:
    string name;
    int age;
    string job;
    int passport = 0;
public:
    Person();
    void setPersonInfo(void);
    void showPersonInfo(void);
    int getPassport(void);
};

#endif // PERSON_H
