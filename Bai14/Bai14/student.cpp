#include "student.h"

Student::Student()
{

}

static bool stringSpace(string name){
    for(char &x : name){
        if(x != ' '){
            return false;
        }
    }
    return true;
}

static void InvalidFullNameException(string fullName){
    if(!((fullName.length() >= 10) && (fullName.length() <= 50))){
        throw "string length must: 10 - 50\n";
    }else{
        if(stringSpace(fullName)){
            throw "Full Name not allowed, Full Name can contain letters (a-z), (A-Z)\n";
        }else{
            for(char &x : fullName){
                if(!(((x >= 'a') && (x <= 'z')) || ((x >= 'A') && (x <= 'Z')))){
                    if(x != ' '){
                        throw "Full Name not allowed, Full Name can contain letters (a-z), (A-Z)\n";
                    }
                }
            }
        }
    }
}

static void InvalidDOBException(string doB){
    if((doB.length() != 10) || stringSpace(doB)){
        throw "doB : dd/MM/YYYY\n";
    }else{
        if((doB[2] != '/') || (doB[5] != '/')){
            throw "doB : dd/MM/YYYY\n";
        }else{
            for(int i = 0; i < doB.length(); i++){
                if((i != 2) && (i != 5)){
                    if(!((doB[i] >= '0') && (doB[i] <= '9'))){
                        throw "doB : dd/MM/YYYY\n";
                    }
                }
            }
            string strDay = doB.substr(0,2);
            string strMonth = doB.substr(3,2);
            string strYear = doB.substr(6,4);
            int day = stoi(strDay);
            int month = stoi(strMonth);
            int year = stoi(strYear);
            int dayMax;
                if (year < 0 || month < 0 || month > 12 || day < 0 || day > 31)
                {
                    throw "invalid\n";
                }
                else
                {
                    switch (month)
                    {
                    case 1:
                    case 3:
                    case 5:
                    case 7:
                    case 8:
                    case 10:
                    case 12:
                        dayMax=31;
                        break;
                    case 2:
                        if ((year%4==0 && year%100!=0) || (year%400==0))
                            dayMax=29;
                        else
                            dayMax=28;
                        break;
                    case 4:
                    case 6:
                    case 9:
                    case 11:
                        dayMax=30;
                        break;
                    }
                    if (day > dayMax)
                    {
                        throw "invalid\n";
                    }
                }
        }
    }
}

static void InvalidPhoneNumberException(string phone){
    if((phone.length() != 10) || stringSpace(phone)){
        throw "Ex: 090xxx, 098xxx, 091xxx, 031xxx, 035xx, 038xx; length = 10\n";
    }else{
        for(char x : phone){
            if(!(x >= '0' && x <= '9')){
                throw "Ex: 090xxx, 098xxx, 091xxx, 031xxx, 035xx, 038xx; length = 10\n";
            }
        }
        string stemp = phone.substr(0,3);
        bool flag = false;
        string arr[] = {"090", "098", "091", "031", "035", "038"};
        for(int i = 0; i < arr->length(); i++){
            if((stemp == arr[i])){
               flag = true;
               break;
            }
        }
        if(flag == false){
            throw "Ex: 090xxx, 098xxx, 091xxx, 031xxx, 035xx, 038xx; length = 10\n";
        }
    }
}

void Student::setFullName(void){
    try{
        cout << "Enter full name:"; cin.ignore(); getline(cin, this->fullName);
        InvalidFullNameException(this->fullName);
    }catch(const char* msg){
        cout << msg;
        Student::setFullName();
    }
}

void Student::setdoB(void){
    try{
        cout << "Enter doB(dd/MM/YYYY):"; getline(cin, this->doB);
        InvalidDOBException(this->doB);
    }catch(const char* msg){
        cout << msg;
        Student::setdoB();
    }
}
void Student::setSex(void){
    cout << "Enter sex:"; getline(cin, this->sex);
}

void Student::setPhoneNumber(void){
    try{
        cout << "Enter phone:"; getline(cin, this->phoneNumber);
        InvalidPhoneNumberException(this->phoneNumber);
    }catch(const char* msg){
        cout << msg;
        Student::setPhoneNumber();
    }
}
void Student::setUniversityName(void){
    cout << "Enter UniversityName:"; getline(cin, this->universityName);
}

string Student::getgradeLevel(void){
    return this->gradeLevel;
}

string Student::getFullName(void){
    return this->fullName;
}

void Student::ShowMyInfor(void){
    cout << "Name: " << this->fullName << "--"
         << "doB:" << this->doB << "--"
         << "sex:" << this->sex << "--"
         << "phoneNumber:" << this->phoneNumber << "--"
         << "universityName:" << this->universityName << "--"
         << "gradeLevel:" << this->gradeLevel << "--";
}

void Student::setMyInfor(void){
    this->setFullName();
    this->setdoB();
    this->setSex();
    this->setPhoneNumber();
    this->setUniversityName();
}
