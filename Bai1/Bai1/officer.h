#ifndef OFFICER_H
#define OFFICER_H

#include <iostream>
using namespace std;

class Officer
{
private:
    string name;
    int age;
    string gender;
    string address;
public:
    Officer();
    Officer(string, int, string, string);
    virtual ~Officer() {}
    void setName(string);
    string getName(void);
    void setAge(int);
    int getAge(void);
    void setGender(string);
    string getGender(void);
    void setAddress(string);
    string getAddress(void);
    virtual void ShowInfo(void);
    virtual void SetInfo(void);
};

#endif // OFFICER_H
