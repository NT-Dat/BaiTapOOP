#ifndef MANAGERDOCUMENT_H
#define MANAGERDOCUMENT_H

#include "document.h"
#include "book.h"
#include "journal.h"
#include "newspaper.h"
#include<list>
#include<memory>

class ManagerDocument
{
private:
    list<unique_ptr<Document>> listDocument;
public:
    ManagerDocument();
    void addDocument(unique_ptr<Document>&);
    void deleteDocument(std::string id);
    void ShowDocumentList(void);
    void search(string);
};

#endif // MANAGERDOCUMENT_H
