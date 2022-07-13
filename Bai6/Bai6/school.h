#ifndef SCHOOL_H
#define SCHOOL_H

#include "student.h"
#include<vector>

class School
{
private:
    vector<Student> school;
public:
    School();
    void addStudent(void);
    void showStudentByAge(int age);
    int countStudentByAge_Hometown(int age, string hometown);
};

#endif // SCHOOL_H
