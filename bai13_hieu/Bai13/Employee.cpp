#include "Employee.h"

//exception handling
static bool stringSpace (string name)
{
    for (char x: name)
    {
        if (x != ' ')
        {
            return false;
        }
    }
            return true;
}
static void nameException (string name)
      {  if (stringSpace(name))
        {
            throw "Full name not valid, please type again!!";
        }
        else 
        {
            for (char x: name)
            {
                if ((x <65) || (90<x<97) || (122<x) )
                {
                    throw "Full name only contain Upper case and lower case letter!!";
                }
            }
        }
      }
static void birthDayException (unsigned int day,unsigned int month,unsigned int year)
{
    int dayMax;
    if ((year<0) || (month<0) || (day<0))
    {
        throw "Invalid birthday";
    }
    else
    {
        switch (month){
        case 1: 
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
         dayMax = 31;
        break;
        case 2:
        if ((year %4==0 &&year %100 !=0) || (year%400==0))
        {
            dayMax = 29;
        }
        else {dayMax = 28;}
        break;
        case 4:
        case 6:
        case 9:
        case 11:
        dayMax = 30;
        break;
        }
    }
    if (day>dayMax)
    {
        throw "Invalid day of birth";
    }

}      
static void phoneException (string phone)
{
    for (char x:phone)
    {
        if ((x<0) || (x>9))
        {
            throw "Invalid phone number";
        }
        else if ((phone.length()>11) || (phone.length()<3))
        {
            throw "phone number must between 3 and 10 digits";
        }
    }
}
/*
Check if the first character of the email id string is an alphabet or not. If not--> Invalid.
Now track back over the string email to find the position the “@” and “.” If “@” or “.” --> Invalid.
If “.” is not present after “@” --> is Invalid.
If “.” or "@" is the last character of the string email --> Invalid.
Otherwise, the email is Valid. */
 //check if the first character is alphabet or not
static bool isChar (string email)
    {
        for (char x: email)
        {
            if ((x <= 'a' && x>='z') || (x<='A' && x>='Z') || (x < '0' && x > '9'))
                return true;
        }
    }   

static void emailException (string email)
{
   if (isChar(email))
   {
       throw "Invalid email ";
   }
   else{
       int at = -1, dot = -1;
    for (int i=0; i<email.length();i++)
    {
        if (email[i]=='@')
        {
            at = i;
        }
        else if (email[i]=='.')
        {
            dot = i;
        }
    }
    if (at==-1 || dot==-1)
    {
        throw "Invalid email syntax";
    }
    if (at>dot)
    {
        throw "Invalid email syntax";
    }
   }
}

int Employee::employee_count = 0;

Employee::Employee()
{
  this-> employee_count++;
}
Employee:: ~ Employee()
{
    
}
void Employee:: setId (string id)
{
    cout<<"Enter id: ";
    cin.ignore();
    getline (cin, this->id);
}
void Employee:: setName ()
{
    try
    {
    cout<<"\nEnter name: ";
    cin.ignore();
    getline (cin, this->name);
    nameException(this->name);
    }catch (const char* fix)
    {
        cout<<"bug fix";
        Employee::setName();
    }
}
void Employee:: setBirth ()
{   int day,month, year;
    try
    {
    cout<<"\nEnter birthday"<<endl;
    cout<<"Enter day: ";
    cin >>day;
    cout<<"\nEnter month: ";
    cin >>month;
    cout<<"\nEnter year: ";
    cin >>year;
    birthDayException ( day,  month,  year);
    this ->birthday = to_string(day) + '/' + to_string (month) + '/' + to_string(year); 
    } catch (const char * fix)
    {
        cout<<"fixed"<<endl;
        Employee::setBirth ();
    }
}
void Employee:: setPhone ()
{
    try{
    cout<<"\nEnter phone number: ";
    getline (cin, this->phone);
    phoneException (this->phone);
    } catch (const char* fix)
    {
        cout<<"fixed"<<endl;
        Employee::setPhone ();
    }

}
void Employee:: setEmail ()
{
    try{
    cout<<"\nEnter email: ";
    getline (cin, this->email);
    emailException (email);
    }
    catch (const char* fix)
    {
        cout<<"fixed"<<endl;
        Employee::setEmail ();
    }
}

string Employee::getId ()
{
    return this->id;
}
void Employee:: setEmployeeType ()
{
    cout<<"\nEnter employee type: ";
    cin>>type;
}
string Employee::getEmployeeType ()
{
    if (type == 0)
    {
        return "Experience";
    }
    else if (type ==1)
    {
        return "Fresher";
    }
    else if (type ==2)
    {
        return "Intern";
    }
    else{
        cout<<"Cannot find suitable employee!!"<<endl;
    }
}
void Employee::addCertificate ()
{
    Certificate certificate;
    certificate.setCertificate();
    this->certificate.push_back (certificate);
}
void Employee:: showCertificate ()
{
    for (auto &x : certificate)
    {
        x.showCertificate();
    }
}

void Employee:: setInfo(){
    this->setName();
    this->setBirth();
    this->setPhone();
    this->setEmail();
}

void Employee:: showInfo()
{
    cout<<"Employee id is: "<<this->id<<endl;
    cout<<"Employee name is: "<<this->name<<endl;
    cout<<"Employee phone is: "<<this->phone<<endl;
    cout<<"Employee email is: "<<this->email<<endl;
    cout<<"Employee birthday is: "<<this->birthday<<endl;
    cout<<"Employee type is: "<<getEmployeeType()<<endl;
}
