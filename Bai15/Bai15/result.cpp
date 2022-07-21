#include "result.h"

Result::Result()
{

}

void Result::setResult(void){
    cout << "Enter semester:"; cin >> this->semester;
    cout << "Enter GPA:"; cin >> this->GPA;
}

void Result::ShowResult(void){
    cout << "Semester:" << this->semester << "--"
        << "GPA:" << this->GPA << endl;
}

int Result::getSemester(void){
    return this->semester;
}

float Result::getGPA(void){
    return this->GPA;
}
