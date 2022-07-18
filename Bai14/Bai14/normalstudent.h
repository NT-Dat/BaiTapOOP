#ifndef NORMALSTUDENT_H
#define NORMALSTUDENT_H

#include "student.h"

class NormalStudent : public Student
{
private:
    int englishScore;
    int entryTestScore;
public:
    NormalStudent();
    void setGradeLevel(void);
    void ShowMyInfor(void);
    void setMyInfor(void);
    int getEnglishScore();
    int getEntryTestScore();
};

#endif // NORMALSTUDENT_H
