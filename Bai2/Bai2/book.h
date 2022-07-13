#ifndef BOOK_H
#define BOOK_H

#include "document.h"

class Book : public Document
{
private:
    std::string author;
    int numberPage;
public:
    Book();
    Book(std::string, std::string, int, std::string, int);
    void setAuthor(std::string);
    std::string getAuthor(void);
    void setNumberPage(int);
    int getNumberPage(void);
    void Show(void);
    void SetInfo();
    string getCategory(void);
};

#endif // BOOK_H
