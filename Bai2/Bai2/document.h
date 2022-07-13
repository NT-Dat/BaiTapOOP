#ifndef DOCUMENT_H
#define DOCUMENT_H

#include<iostream>
using namespace std;

class Document
{
private:
    std::string id;
    std::string nxb;
    int number;
public:
    Document();
    Document(std::string, std::string, int);
    void setId(std::string);
    std::string getId(void);
    void setNxb(std::string);
    std::string getNxb(void);
    void setNumber(int);
    int getNumber(void);
    virtual void Show(void);
    virtual void SetInfo(void);
    virtual string getCategory(void);
};

#endif // DOCUMENT_H
