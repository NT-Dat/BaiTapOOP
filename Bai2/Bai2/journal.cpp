#include "journal.h"

Journal::Journal()
{

}

Journal::Journal(std::string id, std::string nxb, int number, int issueNumber, int monthNumber) :
    Document(id, nxb, number), issueNumber(issueNumber), monthIssue(monthNumber) {}
void Journal::setIssueNumber(int issueNumber){
    this->issueNumber = issueNumber;
}
int Journal::getIssueNumber(void){
    return this->issueNumber;
}
void Journal::setMonthIssue(int monthIssue){
    this->monthIssue = monthIssue;
}
int Journal::getMonthIssue(void){
    return this->monthIssue;
}

void Journal::Show(void){
    Document::Show();
    cout << " - issueNumber: " << getIssueNumber() << " - monthIssue: " << getMonthIssue() << endl;
}

void Journal::SetInfo(){
    Document::SetInfo();
    cout << "Enter issueNumber: "; cin >> issueNumber;
    cout << "Enter monthIssue: "; cin >> monthIssue;
}

string Journal::getCategory(void){
    return "Journal";
}
