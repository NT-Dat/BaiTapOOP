#ifndef CANDIDATE_H
#define CANDIDATE_H

#include<iostream>
#include<string>
using namespace std;

class Candidate
{
private:
    string id;
    string name;
    string address;
    int priority;
public:
    Candidate();
    virtual ~Candidate();
    string getId(void);
    void setInfo(void);
    virtual void showInfo(void);
};

#endif // CANDIDATE_H
