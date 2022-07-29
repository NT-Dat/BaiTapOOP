#include "Certificate.h"

Certificate::Certificate ()
{
    
}
void Certificate :: setCertificate ()
{
    cout<<"Enter Certificate ID: ";
    cin.ignore();
    getline (cin, this->CertificateID);
     cout<<"Enter Certificate ID: ";
     getline (cin, this->CertificateName);
      cout<<"Enter Certificate ID: ";
    getline (cin, this->CertificateRank);
     cout<<"Enter Certificate Date: ";
     getline (cin, this->CertificateDate);
    
}
void Certificate:: showCertificate ()
{
    cout<<"Certificate ID: "<<this->CertificateID<<endl;
    cout<<"Certificate Name: "<<this->CertificateName<<endl;
    cout<<"Certificate Rank: "<<this->CertificateRank<<endl;
    cout<<"Certificate Date: "<<this->CertificateDate<<endl;
}