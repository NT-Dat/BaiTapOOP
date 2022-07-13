#include "managercandidate.h"

void Menu(ManagerCandidate &managerCandidate){
    system("cls");
    cout << "**********   Application Manager Candidate   *********\n";
    cout << "Enter 1: To insert Candidate\n";
    cout << "Enter 2: To show Candidate information\n";
    cout << "Enter 3: To search Candidate by ID\n";
    cout << "Enter 0: To exit\n";
    int choice;
    char type;
    string id;
    do{
        cin >> choice;
        if(choice < 0 || choice > 3){
            cout << "No valid, retry:";
        }
    }while(choice < 0 || choice > 3);
    switch(choice){
    case 1:
        cout << "Enter a: to insert Candidate A\n";
        cout << "Enter b: to insert Candidate B\n";
        cout << "Enter c: to insert Candidate C\n";
        cin >> type;
        switch(type){
        case 'a':
        {
            unique_ptr<Candidate> candidateA(new CandidateA);
            candidateA->setInfo();
            managerCandidate.addCandidate(candidateA);
        }
            break;
        case 'b':
        {
            unique_ptr<Candidate> candidateB(new CandidateB);
            candidateB->setInfo();
            managerCandidate.addCandidate(candidateB);
        }
            break;
        case 'c':
            unique_ptr<Candidate> candidateC(new CandidateC);
            candidateC->setInfo();
            managerCandidate.addCandidate(candidateC);
            break;
        }
        break;
    case 2:
        cout << "Candidate information\n";
        managerCandidate.showCandidateInfor();
        cout << "Enter 0 ---> Menu\n";
        cin >> choice;
        break;
    case 3:
        cout << "Enter ID\n";
        cin >> id;
        managerCandidate.searchById(id);
        cout << "Enter 0 ---> Menu\n";
        cin >> choice;
        break;
   default :
        exit(true);
    }
}

int main()
{
    ManagerCandidate managerCandidate;
    while(true){
        Menu(managerCandidate);
    }
    return 0;
}
