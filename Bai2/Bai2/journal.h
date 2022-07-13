#ifndef JOURNAL_H
#define JOURNAL_H

#include "document.h"

class Journal : public Document
{
private:
    int issueNumber;
    int monthIssue;
public:
    Journal();
    Journal(std::string, std::string, int, int, int);
    void setIssueNumber(int);
    int getIssueNumber(void);
    void setMonthIssue(int);
    int getMonthIssue(void);
    void Show(void);
    void SetInfo(void);
    string getCategory(void);
};

#endif // JOURNAL_H
