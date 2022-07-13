#include "card.h"

Card::Card()
{

}

void Card::setInfoCard(void){
    cout << "Enter id: "; cin >> this->id;
    cout << "Enter borrow date: "; cin >> this->borrowDate;
    cout << "Enter payment date: "; cin >> this->paymentDate;
    cout << "Enter book id: "; cin >> this->bookId;
    cout << "Enter student\n";
    this->student.setInfoStudent();
}

void Card::showInfoCard(void){
    cout << "ID:" << this->id << " - "
         << "Borrow date:" << this->borrowDate << " - "
         << "Payment date:" << this->paymentDate << " - "
         << "Book id:" << this->bookId << " - "
         << "Student: ";
    this->student.showInfoStudent();
}

string Card::getID(void){
    return this->id;
}
