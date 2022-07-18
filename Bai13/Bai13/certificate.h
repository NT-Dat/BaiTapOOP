#ifndef CERTIFICATE_H
#define CERTIFICATE_H

#include<iostream>
using namespace std;

class Certificate
{
private:
    string CertificatedID;
    string CertificateName;
    string CertificateRank;
    string CertificatedDate;
public:
    Certificate();
    void setCertificate(void);
    void showCertificate(void);
    string getCertificatedID(void);
};

#endif // CERTIFICATE_H
