#ifndef STUDENTINSERVICE_H
#define STUDENTINSERVICE_H

#include "formaluniversitystudent.h"

class StudentInService : public FormalUniversityStudent
{
private:
    string whereLink;
public:
    StudentInService();
    string getType(void);
    void setWhereLink(void);
    string getWhereLink(void);
    void ShowMyInfor(void);
    void setMyInfor(void);
};

#endif // STUDENTINSERVICE_H
