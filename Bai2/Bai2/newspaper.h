#ifndef NEWSPAPER_H
#define NEWSPAPER_H

#include "document.h"

class Newspaper : public Document
{
private:
    int dayIssue;
public:
    Newspaper();
    Newspaper(std::string, std::string, int, int);
    void setDayIssue(int);
    int getDayIssue(void);
    void Show(void);
    void SetInfo();
    string getCategory(void);
};

#endif // NEWSPAPER_H
