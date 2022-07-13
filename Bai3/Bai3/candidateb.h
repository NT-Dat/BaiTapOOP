#ifndef CANDIDATEB_H
#define CANDIDATEB_H

#include "candidate.h"

class CandidateB : public Candidate
{
private:
    string subjectsB[3] = {"Math", "Chemistry", "Biology"};
public:
    CandidateB();
    void showInfo(void);
};

#endif // CANDIDATEB_H
