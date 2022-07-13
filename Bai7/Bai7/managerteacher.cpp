#include "managerteacher.h"

ManagerTeacher::ManagerTeacher()
{

}

void ManagerTeacher::addTeacher(void){
    Teacher teacher;
    teacher.setInfo();
    if(this->managerTeacher.count(teacher.getId()) != 0){
        cout << "ID already exists\n";
    }else{
        this->managerTeacher[teacher.getId()] = move(teacher);
    }
}

void ManagerTeacher::showAllTeacher(void){
    int i = 1;
    for(auto it = this->managerTeacher.begin(); it != this->managerTeacher.end(); it++){
        cout << "Teacher " << i << endl;
        it->second.showInfo();
        i++;
    }
}

void ManagerTeacher::deleteTeacherByID(string ID){
    if(this->managerTeacher.count(ID) != 0){
        this->managerTeacher.erase(ID);
    }else{
        cout << "Not found\n";
    }
}

void ManagerTeacher::getRealSalaryByID(string ID){
    if(this->managerTeacher.count(ID) == 0){
        cout << "Not found\n";
    }
    double bonus, penaty;
    cout << "Enter bonus: "; cin >> bonus;
    cout << "Enter penaty: "; cin >> penaty;
    this->managerTeacher[ID].setBonus_Penaty(bonus, penaty);
    cout << "ID " << ID << " Real salary " << this->managerTeacher[ID].getRealSalary() << endl;
}
