#include "formaluniversitystudent.h"

FormalUniversityStudent::FormalUniversityStudent()
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

void FormalUniversityStudent::setID(void){
    cout << "Enter ID:";
    getline(cin, this->ID);
}

void FormalUniversityStudent::setFullName(void){
    try{
        cout << "Enter full name:"; cin.ignore(); getline(cin, this->fullName);
        InvalidFullNameException(this->fullName);
    }catch(const char* msg){
        cout << msg;
        FormalUniversityStudent::setFullName();
    }
}

void FormalUniversityStudent::setdoB(void){
    try{
        cout << "Enter doB(dd/MM/YYYY):"; getline(cin, this->doB);
        InvalidDOBException(this->doB);
    }catch(const char* msg){
        cout << msg;
        FormalUniversityStudent::setdoB();
    }
}

void FormalUniversityStudent::setyearOfAdmission(void){
    cout << "Enter yearOfAdmission:"; cin >> this->yearOfAdmission;
}

void FormalUniversityStudent::setentryPoint(void){
    cout << "Enter entryPoint:";
    cin >> this->entryPoint;
}

void FormalUniversityStudent::addResult(void){
    int choice;
    Result result;
    while(true){
        result.setResult();
        this->result[result.getSemester()] = result;
        cout << "Enter 0 ---> Menu\n";
        cin >> choice;
        if(choice == 0){
            return;
        }
    }
}

void FormalUniversityStudent::showResult(void){
    for(auto &x : this->result){
        x.second.ShowResult();
    }
}

void FormalUniversityStudent::ShowMyInfor(void){
    cout << "ID:" << this->ID << "--"
         << "Name: " << this->fullName << "--"
         << "doB:" << this->doB << "--"
         << "yearOfAdmission:" << this->yearOfAdmission << "--"
         << "entryPoint:" << this->entryPoint << "--";
    this->showResult();
}

void FormalUniversityStudent::setMyInfor(void){
    this->setFullName();
    this->setdoB();
    this->setyearOfAdmission();
    this->setentryPoint();
    this->addResult();
}

string FormalUniversityStudent::getType(void){
    return "FormalUniversityStudent";
}

string FormalUniversityStudent::getID(void){
    return this->ID;
}

float FormalUniversityStudent::getGPA(int semester){
    return this->result[semester].getGPA();
}

int FormalUniversityStudent::getEntryPoint(void){
    return this->entryPoint;
}

int FormalUniversityStudent::getBestGPA(void){
    int gpaMax = 0;
    for(auto &x : this->result){
        if(x.second.getGPA() > gpaMax){
            gpaMax = x.second.getGPA();
        }
    }
    return gpaMax;
}

int FormalUniversityStudent::getyearOfAdmission(void){
    return this->yearOfAdmission;
}
