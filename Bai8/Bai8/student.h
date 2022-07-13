#ifndef STUDENT_H
#define STUDENT_H

#include<iostream>
using namespace std;

class Student
{
private:
    string name;
    int age;
    string CLASS;
public:
    Student();
    void setInfoStudent(void);
    void showInfoStudent(void);
};

#endif // STUDENT_H
