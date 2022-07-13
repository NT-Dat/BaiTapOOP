#include "newspaper.h"

Newspaper::Newspaper()
{

}

Newspaper::Newspaper(std::string id, std::string nxb, int number, int dayIssue) :
    Document(id, nxb, number), dayIssue(dayIssue) {}

void Newspaper::setDayIssue(int dayIssue){
    this->dayIssue = dayIssue;
}
int Newspaper::getDayIssue(void){
    return this->dayIssue;
}

void Newspaper::Show(void){
    Document::Show();
    cout << " - dayIssue: " << getDayIssue() << endl;
}

void Newspaper::SetInfo(){
    Document::SetInfo();
    cout << "Enter dayIssue: "; cin >> dayIssue;
}

string Newspaper::getCategory(void){
    return "Newspaper";
}
