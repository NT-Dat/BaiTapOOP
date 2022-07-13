#include "document.h"

Document::Document()
{

}

Document::Document(string str)
{
    this->str = str;
}

int Document::countWord(void){
    stringstream ss(this->str);
    string word;
    int count = 0;
    while(ss >> word){
        count++;
    }
    return count;
}

int Document::countAa(void){
    map<char, int> mymap;
    for(char x : this->str){
        mymap[x]++;
    }
    return mymap['A'] + mymap['a'];
}

void Document::standard(void){
    stringstream ss(this->str);
    this->str.clear();
    string word;
    while(ss >> word){
        this->str += word + " ";
    }
}

string Document::getString(void){
    return this->str;
}
