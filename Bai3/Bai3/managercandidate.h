#ifndef MANAGERCANDIDATE_H
#define MANAGERCANDIDATE_H

#include "candidate.h"
#include "candidatea.h"
#include "candidateb.h"
#include "candidatec.h"
#include<map>
#include<memory>

class ManagerCandidate
{
private:
    map<string, unique_ptr<Candidate>> managerCandidate;
public:
    ManagerCandidate();
    void addCandidate(unique_ptr<Candidate>&);
    void showCandidateInfor(void);
    void searchById(string);
};

#endif // MANAGERCANDIDATE_H
