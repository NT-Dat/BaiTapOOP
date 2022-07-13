#ifndef WORKER_H
#define WORKER_H

#include "officer.h"

class Worker : public Officer
{
private:
    int level;
public:
    Worker();
    Worker(string, int, string, string, int);
    void setLevel(int);
    int getLevel(void);
    void ShowInfo(void);
    void SetInfo(void);
};

#endif // WORKER_H
