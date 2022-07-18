#include "goodstudent.h"

GoodStudent::GoodStudent()
{

}

void GoodStudent::setGradeLevel(void){
    this->gradeLevel = "GoodStudent";
}

void GoodStudent::ShowMyInfor(void){
    Student::ShowMyInfor();
    cout << "GPA:" << this->gpa << "--"
         << "bestRewardName:" << this->bestRewardName << endl;
}

void GoodStudent::setMyInfor(void){
    Student::setMyInfor();
    this->setGradeLevel();
    cout << "Enter GPA:"; cin >> this->gpa;
    cout << "Enter bestRewardName:"; cin.ignore(); getline(cin, this->bestRewardName);
}

float GoodStudent::getGPA(void){
    return this->gpa;
}
