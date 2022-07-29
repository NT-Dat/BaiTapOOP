#include "Fresher.h"

Fresher::Fresher()
{

}

void Fresher::setInfo(){
    Employee::setInfo();
    cout << "Enter Graduation_date:"; 
    cin >> this->Graduation_date;
    cout << "Enter Graduation_rank:"; 
    cin.ignore(); 
    getline(cin, this->Graduation_rank);
    cout << "Enter Education:"; 
    getline(cin, this->Education);
}

void Fresher::showInfo(){
    Employee::showInfo();
    cout << "Graduation_date:" << this->Graduation_date << endl;
    cout << "Graduation_rank:" << this->Graduation_rank << endl;
    cout << "Education:" << this->Education << endl;
}
