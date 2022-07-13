#ifndef DOCUMENT_H
#define DOCUMENT_H

#include<iostream>
#include<sstream>
#include<map>
#include<set>
#include<unordered_set>

using namespace std;

class Document
{
private:
    string str;
public:
    Document();
    Document(string);
    int countWord(void);
    int countAa(void);
    void standard(void);
    string getString(void);
};

#endif // DOCUMENT_H
