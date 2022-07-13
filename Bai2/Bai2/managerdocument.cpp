#include "managerdocument.h"

ManagerDocument::ManagerDocument()
{

}

void ManagerDocument::addDocument(unique_ptr<Document> &document){
    this->listDocument.push_front(move(document));
}

void ManagerDocument::deleteDocument(std::string id){
    for(auto it = listDocument.begin(); it != listDocument.end();){
        if((*it)->getId() == id){
            it = listDocument.erase(it);
        }else{
            ++it;
        }
    }
}
void ManagerDocument::ShowDocumentList(void){
    for(auto it = listDocument.begin(); it != listDocument.end(); it++){
        (*it)->Show();
    }
}
void ManagerDocument::search(string category){
    for(auto it = listDocument.begin(); it != listDocument.end(); it++){
        if((*it)->getCategory() == category){
            (*it)->Show();
        }
    }
}

