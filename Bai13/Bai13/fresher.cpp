#include "fresher.h"

Fresher::Fresher()
{

}

void Fresher::setInfo(void){
    cout << "Enter Graduation_date:"; cin >> this->Graduation_date;
    cout << "Enter Graduation_rank:"; cin.ignore(); getline(cin, this->Graduation_rank);
    cout << "Enter Education:"; getline(cin, this->Education);
}

void Fresher::ShowInfo(void){
    Employee::ShowInfo();
    cout << "Graduation_date:" << this->Graduation_date << "--";
    cout << "Graduation_rank:" << this->Graduation_rank << "--";
    cout << "Education:" << this->Education << endl;
}
