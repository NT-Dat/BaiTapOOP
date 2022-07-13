#include "managercard.h"

ManagerCard::ManagerCard()
{

}

void ManagerCard::addCard(void){
    Card card;
    card.setInfoCard();
    if(this->managerCard.count(card.getID()) != 0){
        cout << "ID already exists\n";
    }
    this->managerCard[card.getID()] = move(card);
}

void ManagerCard::deleteCard(string ID){
    if(this->managerCard.count(ID) != 0){
        this->managerCard.erase(ID);
    }else{
        cout << "Not found\n";
    }
}

void ManagerCard::showAll(void){
    for(auto &x : this->managerCard){
        x.second.showInfoCard();
    }
}
