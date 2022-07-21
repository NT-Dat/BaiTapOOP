#ifndef RESULT_H
#define RESULT_H

#include<iostream>
using namespace std;

class Result
{
private:
    int semester;
    float GPA;
public:
    Result();
    void setResult(void);
    void ShowResult(void);
    int getSemester(void);
    float getGPA(void);
};

#endif // RESULT_H
