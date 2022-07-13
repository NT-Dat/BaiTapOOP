#ifndef CANDIDATEC_H
#define CANDIDATEC_H

#include "candidate.h"

class CandidateC : public Candidate
{
private:
    string subjectsC[3] = {"Literature", "History", "Geography"};
public:
    CandidateC();
    void showInfo(void);
};

#endif // CANDIDATEC_H
