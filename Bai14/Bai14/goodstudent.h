#ifndef GOODSTUDENT_H
#define GOODSTUDENT_H

#include "student.h"

class GoodStudent : public Student
{
private:
    float gpa;
    string bestRewardName;
public:
    GoodStudent();
    void setGradeLevel(void);
    void ShowMyInfor(void);
    void setMyInfor(void);
    float getGPA(void);
};

#endif // GOODSTUDENT_H
