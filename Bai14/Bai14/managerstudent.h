#ifndef MANAGERSTUDENT_H
#define MANAGERSTUDENT_H

#include "student.h"
#include "goodstudent.h"
#include "normalstudent.h"
#include<vector>
#include<memory>
#include<algorithm>

class managerStudent
{
private:
    vector<unique_ptr<Student>> manager;
public:
    managerStudent();
    void add(unique_ptr<Student>&);
    void showAll(void);
    void showPass(int);
};

#endif // MANAGERSTUDENT_H
