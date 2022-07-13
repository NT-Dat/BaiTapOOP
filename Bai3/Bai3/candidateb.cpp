#include "candidateb.h"

CandidateB::CandidateB()
{

}

void CandidateB::showInfo(void){
    Candidate::showInfo();
    cout << "subjectsB: " << this->subjectsB[0] << " " << this->subjectsB[1] << " " << this->subjectsB[2] << endl;
}
