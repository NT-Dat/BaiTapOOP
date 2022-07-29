#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "Certificate.h"


#include <iostream>
#include <vector>
using namespace std;

class Employee
{
private:
    string id;
    string name;
    string birthday;
    string phone;
    string email;
    int type;
    static int employee_count;
    vector <Certificate> certificate;
    
public:
    Employee();
    virtual ~ Employee();
    virtual void setInfo();
    virtual void showInfo();
    
    void setId(string);
    string getId();
    
    void setName();
    void setBirth ();
    void setPhone ();
    void setEmail();
    
    void setEmployeeType ();
    string getEmployeeType ();
    void addCertificate();
    void showCertificate();
};

#endif
