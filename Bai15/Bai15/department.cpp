#include "department.h"

Department::Department()
{

}

void Department::setNameDepartment(){
    cout << "Enter NameDepartment:"; cin.ignore(); getline(cin, this->nameDepartment);
}

void Department::addStudent(unique_ptr<FormalUniversityStudent>&student){
    this->mapDepartment[student->getID()] = move(student);
}

float Department::getGPAbySemester(string id, int semester){
    return this->mapDepartment[id]->getGPA(semester);
}

int Department::totalStudentByType(string type){
    int count = 0;
    for(auto &x : this->mapDepartment){
        if(x.second->getType() == type){
            count++;
        }
    }
    return count;
}

void Department::showBestStudent(void){
    int entrypointMax = 0;
    for(auto &x : this->mapDepartment){
        if(x.second->getEntryPoint() > entrypointMax){
            entrypointMax = x.second->getEntryPoint();
        }
    }
    for(auto &x : this->mapDepartment){
        if(x.second->getEntryPoint() == entrypointMax){
            x.second->ShowMyInfor();
        }
    }
}

void Department::showStudentinserviceByLink(string link){
    for(auto &x : this->mapDepartment){
        if(x.second->getType() == "StudentInService"){
            if(dynamic_cast<StudentInService&>(*(x.second)).getWhereLink() == link){
                x.second->ShowMyInfor();
            }
        }
    }
}

void Department::showStudent_BestGPA(void){
    int gpaMax = 0;
    for(auto &x : this->mapDepartment){
        if(x.second->getBestGPA() > gpaMax){
            gpaMax = x.second->getBestGPA();
        }
    }
    for(auto &x : this->mapDepartment){
        if(x.second->getBestGPA() == gpaMax){
            x.second->ShowMyInfor();
        }
    }
}

string Department::getNameDepartment(){
    return this->nameDepartment;
}

bool Department::checkID(string ID){
    if(this->mapDepartment.count(ID) != 0){
        return true;
    }else{
        return false;
    }
}

bool comparator(const pair<string, unique_ptr<FormalUniversityStudent>> &a, const pair<string, unique_ptr<FormalUniversityStudent>> &b){
    if(a.second->getType() != b.second->getType()){
        return a.second->getType() < b.second->getType();
    }
    return a.second->getyearOfAdmission() > b.second->getyearOfAdmission();
}

void Department::show_sortStudent(void){
    vector<pair<string, unique_ptr<FormalUniversityStudent>>> vec;

    for (auto& x : this->mapDepartment) {
        vec.push_back(move(x));
    }
    sort(vec.begin(), vec.end(), comparator);
    this->mapDepartment.clear();
    for (int i = 0; i < vec.size(); i++)
    {
        this->mapDepartment[vec[i].first] = move(vec[i].second);
    }
    for(auto &x : this->mapDepartment){
        x.second->ShowMyInfor();
    }
}
