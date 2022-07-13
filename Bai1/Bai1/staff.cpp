#include "staff.h"

Staff::Staff()
{

}

Staff::Staff(string name, int age, string gender, string address, string task) : Officer(name,age,gender,address) {
    this->task = task;
}

void Staff::setTask(string task){
    this->task = task;
}

string Staff::getTask(){
    return this->task;
}

void Staff::SetInfo(void){
    Officer::SetInfo();
    cout << "Enter task: "; getline(cin, task);
}

void Staff::ShowInfo(){
    Officer::ShowInfo();
    cout << " - Task: " << getTask() << endl;
}
