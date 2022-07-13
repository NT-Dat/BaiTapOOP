#include <iostream>

using namespace std;

template<class Type> class LinkedList;

//nodes to be contained with a list
template<class Type> class Node{
private:
    Type data;
    Node<Type>* nextNode;
public:
    Node(Type);
    Type getData(void);
    friend class LinkedList<Type>;
};

template<class Type> Node<Type>::Node(Type data) : data(data), nextNode(NULL) {}

template<class Type> Type Node<Type>::getData(){
    return this->data;
}

//linked list of Node objects
template<class Type> class LinkedList{
private:
    Node<Type> *head;
    bool isEmpty(void);
public:
    LinkedList();
    ~LinkedList();
    int Size();
    Node<Type>* begin(void);
    Node<Type>* end(void);
    void insertBegin(Type);
    void insertEnd(Type);
    void insertPos(int, Type);
    void deleteBegin();
    void deleteEnd();
    void deletePos(int);
};

template<class Type> LinkedList<Type>::LinkedList() : head(NULL) {}
template<class Type> LinkedList<Type>::~LinkedList(){
    if(!isEmpty()){
        Node<Type> *current = this->head;
        Node<Type> *temp;
        while(current != NULL){
            temp = current;
            current = current->nextNode;
            delete temp;
        }
    }
}

template<class Type> bool LinkedList<Type>::isEmpty(){
    if(this->head == NULL){
        return true;
    }else{
        return false;
    }
}

template<class Type> int LinkedList<Type>::Size(){
    int cnt = 0;
    Node<Type> *current = this->head;
    while(current != NULL){
        ++cnt;
        current = current->nextNode;
    }
    return cnt;
}

template<class Type> void LinkedList<Type>::insertBegin(Type data){
    if(isEmpty()){
        head = new Node<Type>(data);
    }else{
        Node<Type> *temp = new Node<Type>(data);
        temp->nextNode = this->head;
        this->head = temp;
    }
}

template<class Type> void LinkedList<Type>::insertEnd(Type data){
    if(isEmpty()){
        head = new Node<Type>(data);
    }else{
        Node<Type> *temp = new Node<Type>(data);
        Node<Type> *current = this->head;
        while(current->nextNode != NULL){
            current = current->nextNode;
        }
        current->nextNode = temp;
    }
}

template<class Type> void LinkedList<Type>::insertPos(int pos, Type data){
    if(isEmpty() || pos == 0){
        head = new Node<Type>(data);
    }else{
        Node<Type> *temp = new Node<Type>(data);
        Node<Type> *current = this->head;
        for(int i = 0; i < pos - 1; i++){
            current = current->nextNode;
        }
        temp->nextNode = current->nextNode;
        current->nextNode = temp;
    }
}

template<class Type> void LinkedList<Type>::deleteBegin(){
    if(isEmpty()){
        return;
    }else{
        this->head = this->head->nextNode;
    }
}

template<class Type> void LinkedList<Type>::deleteEnd(){
    if(isEmpty()){
        return;
    }else{
        Node<Type> *pre = NULL;
        Node<Type> *current = this->head;
        while(current->nextNode != NULL){
            pre = current;
            current = current->nextNode;
        }
        pre->nextNode = NULL;
    }
}

template<class Type> void LinkedList<Type>::deletePos(int pos){
    Node<Type> *pre = NULL;
    Node<Type> *tmp = this->head;
    for(int i = 0; i < pos; i++){
        pre = tmp;
        tmp = tmp->nextNode;
    }
    pre->nextNode = tmp->nextNode;
}

template<class Type> Node<Type>* LinkedList<Type>::begin(void){
    return this->head;
}

template<class Type> Node<Type>* LinkedList<Type>::end(void){
    Node<Type>* current = this->head;
    while(current != NULL){
        current = current->nextNode;
    }
    return current;
}

class Student{
private:
    string name;
    int age;
    string address;
public:
    Student(){}
    Student(string name, int age, string address) : name(name), age(age), address(address) {}
    void Print(void){
        cout << "Name: " << this->name << " *** Age: " << this->age
             << " *** Address: " << this->address << endl;
    }
};

int main(){
    LinkedList<Student> list;
    list.insertEnd(Student("Nguyen Van A", 20, "Ha Noi"));
    list.insertEnd(Student("Nguyen Van B", 21, "HCM"));
    list.insertEnd(Student("Nguyen Van C", 22, "VN"));
    list.insertPos(1,Student("Nguyen Van D", 20, "Ha Noi"));

    return 0;
}
