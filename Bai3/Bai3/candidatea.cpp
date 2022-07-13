#include "candidatea.h"

CandidateA::CandidateA()
{

}

void CandidateA::showInfo(void){
    Candidate::showInfo();
    cout << "subjectsA: " << this->subjectsA[0] << " " << this->subjectsA[1] << " " << this->subjectsA[2] << endl;
}
