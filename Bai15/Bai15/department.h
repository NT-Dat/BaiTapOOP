#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "formaluniversitystudent.h"
#include "studentinservice.h"
#include<memory>
#include<map>

class Department
{
private:
    string nameDepartment;
    map<string, unique_ptr<FormalUniversityStudent>> mapDepartment;
public:
    Department();
    void setNameDepartment();
    void addStudent(unique_ptr<FormalUniversityStudent>&);
    float getGPAbySemester(string, int);
    int totalStudentByType(string);
    void showBestStudent(void);
    void showStudentinserviceByLink(string);
};

#endif // DEPARTMENT_H
