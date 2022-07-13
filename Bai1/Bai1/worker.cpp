#include "worker.h"

Worker::Worker()
{

}

Worker::Worker(string name, int age, string gender, string address, int level) : Officer(name,age,gender,address) {
    this->level = level;
}

void Worker::setLevel(int level){
    this->level = level;
}

int Worker::getLevel(){
    return this->level;
}

void Worker::SetInfo(void){
    Officer::SetInfo();
    cout << "Enter level: "; cin >> level;
}

void Worker::ShowInfo(){
    Officer::ShowInfo();
    cout << " - Level: " << getLevel() << endl;
}
