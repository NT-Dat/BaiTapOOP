#include "managerdocument.h"

void Menu(ManagerDocument &managerdocument){
    system("cls");
    cout << "**********   Application Manager Document   *********\n";
    cout << "Enter 1: To insert document\n";
    cout << "Enter 2: To remove document by id\n";
    cout << "Enter 3: To show information documents\n";
    cout << "Enter 4: To search document by category\n";
    cout << "Enter 0: To exit\n";
    int choice;
    char type;
    string category;
    string Name = "No name";
    do{
        cin >> choice;
        if(choice < 0 || choice > 4){
            cout << "No valid, retry:";
        }
    }while(choice < 0 || choice > 4);
    switch(choice){
    case 1:
        cout << "Enter a: to insert Book\n";
        cout << "Enter b: to insert Newspaper\n";
        cout << "Enter c: to insert Journal\n";
        cin >> type;
        switch(type){
        case 'a':
        {
            unique_ptr<Document> book(new Book);
            book->SetInfo();
            managerdocument.addDocument(book);
        }
            break;
        case 'b':
        {
            unique_ptr<Document> newspaper(new Newspaper);
            newspaper->SetInfo();
            managerdocument.addDocument(newspaper);
        }
            break;
        case 'c':
        {
            unique_ptr<Document> journal(new Journal);
            journal->SetInfo();
            managerdocument.addDocument(journal);
        }
            break;
        }
        break;
    case 2:
        cout << "Enter id of document\n";
        cin.ignore();
        getline(cin,Name);
        managerdocument.deleteDocument(Name);
        cout << "Enter 0 ---> Menu\n";
        cin >> choice;
        break;
    case 3:
        cout << "Information document\n";
        managerdocument.ShowDocumentList();
        cout << "Enter 0 ---> Menu\n";
        cin >> choice;
        break;
    case 4:
        cout << "Enter a to search book\n";
        cout << "Enter b to search newspaper\n";
        cout << "Enter c to search journal\n";
        cin >> category;
        managerdocument.search(category);
        cout << "Enter 0 ---> Menu\n";
        cin >> choice;

        break;
    default :
        exit(true);
    }
}

int main()
{
    ManagerDocument managerdocument;
    while(true){
        Menu(managerdocument);
    }
    return 0;
}
