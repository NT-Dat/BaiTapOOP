#include "book.h"

Book::Book()
{

}

Book::Book(std::string id, std::string nxb, int number, std::string author, int numberPage) :
    Document(id,nxb,number) , author(author), numberPage(numberPage) {}

void Book::setAuthor(std::string author){
    this->author = author;
}
std::string Book::getAuthor(void){
    return this->author;
}
void Book::setNumberPage(int numberPage){
    this->numberPage = numberPage;
}
int Book::getNumberPage(void){
    return this->numberPage;
}

void Book::Show(void){
    Document::Show();
    cout << " - author: " << getAuthor() << " - numberPage: " << getNumberPage() << endl;
}

void Book::SetInfo(){
    Document::SetInfo();
    cin.ignore(); cout << "Enter author: "; getline(cin, author);
    cout << "Enter numberPage: "; cin >> numberPage;
}

string Book::getCategory(void){
    return "Book";
}
