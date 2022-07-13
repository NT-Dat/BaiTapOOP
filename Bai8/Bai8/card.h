#ifndef CARD_H
#define CARD_H

#include "student.h"

class Card
{
private:
    string id;
    int borrowDate;
    int paymentDate;
    int bookId;
    Student student;
public:
    Card();
    void setInfoCard(void);
    void showInfoCard(void);
    string getID(void);
};

#endif // CARD_H
