#include "school.h"

School::School()
{

}

void School::addStudent(void){
    Student student;
    student.setInfo();
    this->school.push_back(move(student));
}

void School::showStudentByAge(int age){
    cout << "Student " << age << " year old\n";
    for(int i = 0; i < this->school.size(); i++){
        if(this->school[i].getAge() == age){
            this->school[i].showInfo();
        }
    }
}

int School::countStudentByAge_Hometown(int age, string hometown){
    int count = 0;
    for(int i = 0; i < this->school.size(); i++){
        if(this->school[i].getAge() == age && this->school[i].getHometown() == hometown){
            count++;
        }
    }
    return count;
}
