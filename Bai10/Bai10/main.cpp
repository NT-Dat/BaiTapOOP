#include <iostream>

#include "document.h"
using namespace std;

int main()
{
    string str;
    cout << "Enter string: ";
    getline(cin, str);
    Document doc(str);
    cout << "Total word: " << doc.countWord() << endl;
    cout << "Total A a: " << doc.countAa() << endl;
    doc.standard();
    cout << "Standard: " << doc.getString();
    return 0;
}
