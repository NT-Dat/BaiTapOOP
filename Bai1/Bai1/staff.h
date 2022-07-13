#ifndef STAFF_H
#define STAFF_H

#include "officer.h"

class Staff : public Officer
{
private:
    string task;
public:
    Staff();
    Staff(string, int, string, string, string);
    void setTask(string);
    string getTask(void);
    void ShowInfo(void);
    void SetInfo(void);
};

#endif // STAFF_H
