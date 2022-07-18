#include "certificate.h"

Certificate::Certificate()
{

}

void Certificate::setCertificate(void){
    cout << "Enter CertificatedID:";cin.ignore(); getline(cin, this->CertificatedID);
    cout << "Enter CertificateName:"; getline(cin, this->CertificateName);
    cout << "Enter CertificateRank:"; getline(cin, this->CertificateRank);
    cout << "Enter CertificatedDate:"; getline(cin, this->CertificatedDate);
}

void Certificate::showCertificate(void){
    cout << "CertificatedID:" << this->CertificatedID << "--";
    cout << "CertificateName:" << this->CertificateName << "--";
    cout << "CertificateRank:" << this->CertificateRank << "-- ";
    cout << "CertificatedDate:" << this->CertificatedDate << "--";
}

string Certificate::getCertificatedID(void){
    return this->CertificatedID;
}
