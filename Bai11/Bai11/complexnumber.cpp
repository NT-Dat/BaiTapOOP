#include "complexnumber.h"

ComplexNumber::ComplexNumber()
{

}

istream& operator >> (istream& is, ComplexNumber& complexNumber){
    cout << "Enter realPart: "; is >> complexNumber.realPart;
    cout << "Enter imaginaryPart: "; is >> complexNumber.imaginaryPart;
    return is;
}

ostream& operator << (ostream& os, const ComplexNumber& complexNumber){
    os << complexNumber.realPart << " +" << complexNumber.imaginaryPart << "i";
    return os;
}

ComplexNumber operator + (const ComplexNumber& complexNumber1, const ComplexNumber& complexNumber2){
    ComplexNumber temp;
    temp.realPart = complexNumber1.realPart + complexNumber2.realPart;
    temp.imaginaryPart = complexNumber1.imaginaryPart + complexNumber2.imaginaryPart;
    return temp;
}

ComplexNumber operator * (const ComplexNumber& complexNumber1, const ComplexNumber& complexNumber2){
    ComplexNumber temp;
    temp.realPart = complexNumber1.realPart * complexNumber2.realPart - complexNumber1.imaginaryPart * complexNumber2.imaginaryPart;
    temp.imaginaryPart = complexNumber1.realPart * complexNumber2.imaginaryPart + complexNumber1.imaginaryPart * complexNumber2.realPart;
    return temp;
}
