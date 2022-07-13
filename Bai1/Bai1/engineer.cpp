#include "engineer.h"

Engineer::Engineer()
{

}

Engineer::Engineer(string name, int age, string gender, string address, string branch) : Officer(name,age,gender,address) {
    this->branch = branch;
}

void Engineer::setBranch(string branch){
    this->branch = branch;
}

string Engineer::getBranch(){
    return this->branch;
}

void Engineer::SetInfo(void){
    Officer::SetInfo();
    cout << "Enter branch: "; getline(cin, branch);
}

void Engineer::ShowInfo(){
    Officer::ShowInfo();
    cout << " - Branch: " << getBranch() << endl;
}
