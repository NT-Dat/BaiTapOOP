#ifndef CANDIDATEA_H
#define CANDIDATEA_H

#include "candidate.h"

class CandidateA : public Candidate
{
private:
    string subjectsA[3] = {"Math", "Physic", "Chemistry"};
public:
    CandidateA();
    void showInfo(void);
};

#endif // CANDIDATEA_H
