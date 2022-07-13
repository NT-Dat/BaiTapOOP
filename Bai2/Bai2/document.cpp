#include "document.h"

Document::Document()
{

}

Document::Document(std::string id, std::string nxb, int number) : id(id), nxb(nxb), number(number) {}

void Document::setId(std::string id) {
    this->id = id;
}
std::string Document::getId(void) {
    return this->id;
}
void Document::setNxb(std::string nxb) {
    this->nxb = nxb;
}
std::string Document::getNxb(void) {
    return this->nxb;
}
void Document::setNumber(int number) {
    this->number = number;
}
int Document::getNumber(void) {
    return this->number;
}

void Document::Show(void){
    cout << "id: " << getId() << " - nxb: " << getNxb() << " - number: " << getNumber();
}

void Document::SetInfo(){
    cin.ignore(); cout << "Enter id: "; getline(cin, id);
    cout << "Enter nxb: "; getline(cin, nxb);
    cout << "Enter number: "; cin >> number;
}

string Document::getCategory(void){
    return "Document";
}
