#ifndef FORMALUNIVERSITYSTUDENT_H
#define FORMALUNIVERSITYSTUDENT_H

#include<iostream>
#include "result.h"
#include<map>
using namespace std;

class FormalUniversityStudent
{
private:
    string ID;
    string fullName;
    string doB;
    int yearOfAdmission;
    int entryPoint;
    map<int, Result> result;
public:
    FormalUniversityStudent();
    virtual ~FormalUniversityStudent(){};
    void setID(void);
    void setFullName(void);
    void setdoB(void);
    void setyearOfAdmission(void);
    void setentryPoint(void);
    void addResult(void);
    void showResult(void);
    string getID(void);
    float getGPA(int);
    int getEntryPoint(void);
    virtual string getType(void);
    virtual void ShowMyInfor(void);
    virtual void setMyInfor(void);
};

#endif // FORMALUNIVERSITYSTUDENT_H
