#include "user.h"

User::User(){}
User::~User(){}
User::User(const std::string &name){
    this->name = name;
    this->win = 0;
    this->loss = 0;
    this->draw = 0;
}
std::string User::getName(){
    return this->name;
}
void User::setName(const std::string &name){
    this->name = name;
}

int User::getWin(){
    return this->win;
}
void User::setWin(const int &win){
    this->win = win;
}

int User::getLoss(){
    return this->loss;
}
void User::setLoss(const int &loss){
    this->loss = loss;
}

int User::getDraw(){
    return this->draw;
}
void User::setDraw(const int &draw){
    this->draw = draw;
}

void User::ShowInfo(){
    std::cout<<" Name: "<< this->getName()<<std::endl;
    std::cout<<" Win: "<< this->getWin()<<std::endl;
    std::cout<<" Loss: "<< this->getLoss()<<std::endl;
    std::cout<<" Draw: "<< this->getDraw()<<std::endl;

}
