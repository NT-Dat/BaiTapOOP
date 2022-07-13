#include "officer.h"

Officer::Officer()
{

}

Officer::Officer(string name, int age, string gender, string address) {
    this->name = name;
    this->age = age;
    this->gender = gender;
    this->address = address;
}

void Officer::setName(string name){
    this->name = name;
}

string Officer::getName(){
    return this->name;
}

void Officer::setAge(int age){
    this->age = age;
}

int Officer::getAge(){
    return this->age;
}

void Officer::setGender(string gender){
    this->gender = gender;
}

string Officer::getGender(){
    return this->gender;
}

void Officer::setAddress(string address){
    this->address = address;
}

string Officer::getAddress(){
    return this->address;
}

void Officer::SetInfo(){
    cin.ignore(); cout << "Enter name: "; getline(cin, name);
    cout << "Enter age: "; cin >> age; setAge(age);
    cin.ignore(); cout << "Enter gender: "; getline(cin, gender);
    cout << "Enter address: "; getline(cin, address);
}

void Officer::ShowInfo(void){
    cout << "Name: " << getName() << " - Age: " << getAge() << " - Gender: " << getGender()
         << " - Address: " << getAddress();
}
