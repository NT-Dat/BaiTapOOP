#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H

#include<iostream>
using namespace std;

class ComplexNumber
{
private:
    int realPart;
    int imaginaryPart;
public:
    ComplexNumber();
    friend istream& operator >> (istream& is, ComplexNumber& complexNumber);
    friend ostream& operator << (ostream& os, const ComplexNumber& complexNumber);
    friend ComplexNumber operator + (const ComplexNumber& complexNumber1, const ComplexNumber& complexNumber2);
    friend ComplexNumber operator * (const ComplexNumber& complexNumber1, const ComplexNumber& complexNumber2);
};

#endif // COMPLEXNUMBER_H
