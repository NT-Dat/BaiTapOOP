#ifndef TEACHER_H
#define TEACHER_H

#include<iostream>

using namespace std;

class Teacher
{
private:
    double salary;
    double bonus = 0;
    double penaty = 0;
    double realSalary;
    string name;
    int age;
    string hometown;
    string id;
public:
    Teacher();
    void setInfo(void);
    void showInfo(void);
    string getId(void);
    void setBonus_Penaty(double, double);
    double getRealSalary(void);
};

#endif // TEACHER_H
