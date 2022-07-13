#ifndef STUDENT_H
#define STUDENT_H

#include<iostream>
using namespace std;

class Student
{
private :
    string name;
    int age;
    string hometown;
    int classStudent;
public:
    Student();
    void setInfo(void);
    void showInfo(void);
    int getAge(void);
    string getHometown(void);
};

#endif // STUDENT_H
