#ifndef MANAGERCARD_H
#define MANAGERCARD_H

#include "card.h"
#include<map>
class ManagerCard
{
private:
    map<string, Card> managerCard;
public:
    ManagerCard();
    void addCard(void);
    void deleteCard(string);
    void showAll(void);
};

#endif // MANAGERCARD_H
