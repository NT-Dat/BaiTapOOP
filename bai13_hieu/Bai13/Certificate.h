#ifndef CERTIFICATE_H
#define CERTIFICATE_H
using namespace std;
#include <iostream>
class Certificate 
{
private:
    string CertificateID;
    string CertificateName;
    string CertificateRank;
    string CertificateDate;
public:
    Certificate();
    void setCertificate ();
    void showCertificate();
};

#endif
