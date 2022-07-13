#include "managercandidate.h"

ManagerCandidate::ManagerCandidate()
{

}

void ManagerCandidate::addCandidate(unique_ptr<Candidate>& candidate){
    this->managerCandidate[candidate->getId()] = move(candidate);
}

void ManagerCandidate::showCandidateInfor(void){
    for (auto itr = this->managerCandidate.begin(); itr != this->managerCandidate.end(); ++itr) {
            itr->second->showInfo();
        }
}

void ManagerCandidate::searchById(string id){
    if(this->managerCandidate.count(id) != 0){
        this->managerCandidate[id]->showInfo();
    }else{
        cout << "Not found\n";
    }
}
