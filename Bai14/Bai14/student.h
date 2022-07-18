#ifndef STUDENT_H
#define STUDENT_H

#include<iostream>
using namespace std;

class Student
{
private:
    string fullName;
    string doB;
    string sex;
    string phoneNumber;
    string universityName;
protected:
    string gradeLevel;
public:
    Student();
    virtual ~Student(){};
    virtual void ShowMyInfor(void);
    virtual void setMyInfor(void);
    void setFullName(void);
    void setdoB(void);
    void setSex(void);
    void setPhoneNumber(void);
    void setUniversityName(void);
    virtual void setGradeLevel(void) = 0;
    string getgradeLevel(void);
    string getFullName(void);
};

#endif // STUDENT_H
