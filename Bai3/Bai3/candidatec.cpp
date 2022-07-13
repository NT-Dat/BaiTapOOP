#include "candidatec.h"

CandidateC::CandidateC()
{

}

void CandidateC::showInfo(void){
    Candidate::showInfo();
    cout << "subjectsC: " << this->subjectsC[0] << " " << this->subjectsC[1] << " " << this->subjectsC[2] << endl;
}
