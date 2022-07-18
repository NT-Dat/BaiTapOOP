#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<iostream>
#include "certificate.h"
#include<vector>
#include<string>
using namespace std;

class Employee
{
private:
    string ID;
    string FullName;
    string BirthDay;
    string Phone;
    string Email;
    int Employee_type;
    static int Employee_count;
    vector<Certificate> certificate;
public:
    Employee();
    virtual ~Employee(){};
    virtual void ShowInfo(void);
    virtual void setInfo(void);
    void setID(string);
    void setFullName(void);
    void setBirthDay(void);
    void setEmail(void);
    void setPhone(void);
    void setEmployee_type(void);
    int getEmployee_type(void);
    void addCertificate(void);
    void showCertificate(void);
};

#endif // EMPLOYEE_H
