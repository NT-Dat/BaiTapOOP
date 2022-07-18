#include "normalstudent.h"

NormalStudent::NormalStudent()
{

}

void NormalStudent::setGradeLevel(void){
    this->gradeLevel = "NormalStudent";
}

void NormalStudent::ShowMyInfor(void){
    Student::ShowMyInfor();
    cout << "englishScore:" << this->englishScore << "--"
         << "entryTestScore:" << this->entryTestScore << endl;
}

void NormalStudent::setMyInfor(void){
    Student::setMyInfor();
    this->setGradeLevel();
    cout << "Enter englishScore:"; cin >> this->englishScore;
    cout << "Enter entryTestScore:"; cin >> this->entryTestScore;
}

int NormalStudent::getEnglishScore(){
    return this->englishScore;
}

int NormalStudent::getEntryTestScore(){
    return this->entryTestScore;
}
