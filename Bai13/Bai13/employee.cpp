#include "employee.h"

static bool stringEmpty(string fullName){
    for(char &x : fullName){
        if(x != ' '){
            return false;
        }
    }
    return true;
}

static void FullNameException(string fullName){
    if(stringEmpty(fullName)){
        throw "Full Name not allowed, Full Name can contain letters (a-z), (A-Z)\n";
    }else{
        for(char &x : fullName){
            if((x < 65) || (x > 90 && x < 97) || (x > 122)){
                if(x != 32){
                    throw "Full Name not allowed, Full Name can contain letters (a-z), (A-Z)\n";
                }
            }
        }
    }

}

static void BirthDayException(int day, int month, int year){
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

static void PhoneException(string phone){
    if(stringEmpty(phone)){
        throw "phone invalid\n";
    }else{
        if(phone.length() != 10){
            throw "phone invalid\n";
        }else{
            for(char x : phone){
                if(!(x >= '0' && x <= '9')){
                    throw "phone invalid\n";
                }
            }
        }
    }
}

static void EmailException(string email){
    bool atFlag = false;
    bool comFlag = false;
    for(char x : email){
        if(x == '@'){
            atFlag = true;
        }
    }
    int sizeEmail = email.length();
    if(email.substr((sizeEmail-4),(sizeEmail-1)) == ".com") {
        comFlag = true;
    }
    if(!(atFlag && comFlag)){
        throw "email invalid\n";
    }
}

int Employee::Employee_count = 0;

Employee::Employee()
{
    this->Employee_count++;
}

void Employee::setID(string id){
    this->ID = id;
}

void Employee::setFullName(void){
    try{
        cout << "Enter full name:"; getline(cin, this->FullName);
        FullNameException(this->FullName);
    }catch(const char* msg){
        cout << msg;
        Employee::setFullName();
    }
}

void Employee::setBirthDay(void){
    int day, month, year;
    try{
        cout << "Enter day:";
        cin >> day;
        cout << "Enter month:";
        cin >> month;
        cout << "Enter year:";
        cin >> year;
        BirthDayException(day, month, year);
        this->BirthDay = to_string(day) + "/" + to_string(month) + "/" + to_string(year);
    }catch(const char* msg){
        cout << msg;
        Employee::setBirthDay();
    }
}

void Employee::setEmail(void){
    try{
        cout << "Enter email:"; getline(cin, this->Email);
        EmailException(this->Email);
    }catch(const char* msg){
        cout << msg;
        Employee::setEmail();
    }
}

void Employee::setPhone(void){
    try{
        cout << "Enter phone:"; getline(cin, this->Phone);
        PhoneException(this->Phone);
    }catch(const char* msg){
        cout << msg;
        Employee::setPhone();
    }
}

void Employee::setEmployee_type(void){
    cout << "Enter Employee_type:"; cin >> this->Employee_type;
}

int Employee::getEmployee_type(void){
    return this->Employee_type;
}

string getNameEmployee_type(int type){
    if(type == 0){
        return "Experience";
    }else if(type == 1){
        return "fresher";
    }else{
        return "Intern";
    }
}

void Employee::setInfo(void){
    Employee::setFullName();
    Employee::setBirthDay();
    Employee::setPhone();
    Employee::setEmail();
    Employee::setEmployee_type();
}

void Employee::ShowInfo(void){
    cout << "ID:" << this->ID << "--"
         << "FullName:" << this->FullName << "--"
         << "BirthDay:" << this->BirthDay << "--"
         << "Phone:" << this->Phone << "--"
         << "Email:" << this->Email << "--"
         << "Employee_type:" << getNameEmployee_type(this->Employee_type) << "--";
}
