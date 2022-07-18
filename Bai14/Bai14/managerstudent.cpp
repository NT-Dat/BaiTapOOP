#include "managerstudent.h"

managerStudent::managerStudent()
{

}

static bool compare(unique_ptr<Student>&student1,unique_ptr<Student>&student2)
{
    if(student1->getgradeLevel() != student2->getgradeLevel()){
        return (student1->getgradeLevel() < student2->getgradeLevel());
    }else if((student1->getgradeLevel() == student2->getgradeLevel()) &&  (student1->getgradeLevel() == "GoodStudent")){
        if(dynamic_cast<GoodStudent&>(*student1).getGPA() != dynamic_cast<GoodStudent&>(*student2).getGPA()){
            return dynamic_cast<GoodStudent&>(*student1).getGPA() > dynamic_cast<GoodStudent&>(*student2).getGPA();
        }else{
            return dynamic_cast<GoodStudent&>(*student1).getFullName() < dynamic_cast<GoodStudent&>(*student2).getFullName();
        }
    }
    if(dynamic_cast<NormalStudent&>(*student1).getEntryTestScore() != dynamic_cast<NormalStudent&>(*student2).getEntryTestScore()){
        return dynamic_cast<NormalStudent&>(*student1).getEntryTestScore() > dynamic_cast<NormalStudent&>(*student2).getEntryTestScore();
    }else{
        if(dynamic_cast<NormalStudent&>(*student1).getEnglishScore() != dynamic_cast<NormalStudent&>(*student2).getEnglishScore()){
            return dynamic_cast<NormalStudent&>(*student1).getEnglishScore() > dynamic_cast<NormalStudent&>(*student2).getEnglishScore();
        }
    }
    return dynamic_cast<NormalStudent&>(*student1).getEnglishScore() > dynamic_cast<NormalStudent&>(*student2).getEnglishScore();
}

void managerStudent::add(unique_ptr<Student>&student){
    student->setMyInfor();
    this->manager.push_back(move(student));
}

void managerStudent::showAll(void){
    for(auto &x : this->manager){
        x->ShowMyInfor();
    }
}

void managerStudent::showPass(int number){
    sort(this->manager.begin(), this->manager.end(), compare);
    for(int i = 0; i < number; i++){
        this->manager[i]->ShowMyInfor();
    }
}
