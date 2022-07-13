#ifndef ENGINEER_H
#define ENGINEER_H

#include "officer.h"

class Engineer : public Officer
{
private:
    string branch;
public:
    Engineer();
    Engineer(string, int, string, string, string);
    void setBranch(string);
    string getBranch(void);
    void ShowInfo(void);
    void SetInfo(void);
};

#endif // ENGINEER_H
