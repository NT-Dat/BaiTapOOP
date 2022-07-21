#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "formaluniversitystudent.h"
#include "studentinservice.h"
#include<memory>
#include<map>
#include<vector>
#include<algorithm>

class Department
{
private:
    string nameDepartment;
    map<string, unique_ptr<FormalUniversityStudent>> mapDepartment;
public:
    Department();
    void setNameDepartment();
    string getNameDepartment();
    void addStudent(unique_ptr<FormalUniversityStudent>&);
    float getGPAbySemester(string, int);
    int totalStudentByType(string);
    void showBestStudent(void);
    void showStudentinserviceByLink(string);
    void showStudent_BestGPA(void);
    bool checkID(string);
    void show_sortStudent(void);
};

#endif // DEPARTMENT_H
