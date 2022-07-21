#include "studentinservice.h"

StudentInService::StudentInService()
{

}

void StudentInService::setWhereLink(void){
    cout << "Enter where link:";getline(cin, this->whereLink);
}

void StudentInService::ShowMyInfor(void){
    FormalUniversityStudent::ShowMyInfor();
    cout << "where link:" << this->whereLink << endl;
}

void StudentInService::setMyInfor(void){
    FormalUniversityStudent::setMyInfor();
    this->setWhereLink();
}

string StudentInService::getType(void){
    return "StudentInService";
}

string StudentInService::getWhereLink(void){
    return this->whereLink;
}
