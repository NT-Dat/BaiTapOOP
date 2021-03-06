#include "manager.h"

manager::manager()
{

}

void manager::addDepartment(void){
    unique_ptr<Department> department(new Department);
    department->setNameDepartment();
    if(this->managerUniversity.count(department->getNameDepartment()) != 0){
        cout << "Department already exist\n";
    }else{
        this->managerUniversity[department->getNameDepartment()] = move(department);
    }
}

void manager::addStudent(string namedepartment, unique_ptr<FormalUniversityStudent>&student){
    student->setID();
    bool check = false;
    for(auto &x : this->managerUniversity){
        if(x.second->checkID(student->getID()) == true){
            check = true;
            break;
        }
    }
    if(check == true){
        cout << "Student already exist\n";
    }else{
        student->setMyInfor();
        this->managerUniversity[namedepartment]->addStudent(student);
    }
}

int manager::totalStudent_type_Department(string namedepartment, string type){
    if(this->managerUniversity.count(namedepartment) == 0){
        cout << "Not found\n";
        return 0;
    }else{
        return this->managerUniversity[namedepartment]->totalStudentByType(type);
    }
}

void manager::showBestStudent_Department(string namedepartment){
    this->managerUniversity[namedepartment]->showBestStudent();
}

void manager::showStudentinserviceByLink_Department(string nameDepartment, string link){
    this->managerUniversity[nameDepartment]->showStudentinserviceByLink(link);
}

void manager::showStudent_BestGPA(string nameDepartment){
    this->managerUniversity[nameDepartment]->showStudent_BestGPA();
}

void manager::show_sortStudent_Department(string nameDepartment){
    this->managerUniversity[nameDepartment]->show_sortStudent();
}
