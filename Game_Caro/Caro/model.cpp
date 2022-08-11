#include "model.h"

Model::Model(){}
Model::~Model(){}

int Model::getSize(){
    return this->size;
}

void Model::setSize(const int &size){
    this->size = size;
}

int Model::getCount(){
    return this->count;
}

std::map<std::string,User> Model::getUsers(){
    return this->users;
}

std::vector<std::vector<char>> Model::getTurn(){
    return this->turns;
}

void Model::CreateUser(User &user){
    if(this->FindFile(user.getName()) == true){
        std::cout << "user already exist\n";
    }else{
        this->WriteInfo(user);
    }
}

void Model::ShowUser(const std::string &name){
    users[name].ShowInfo();
}

void Model::addTurn(const int &row, const int &col, const char OX){
    turns[row][col] = OX;
    count++;
}

void Model::createArrModel2D(){
    turns.resize(size);
    for(int i = 0; i<size; i++){
        turns[i].resize(size);
    }
    std::vector<std::vector<char>> arrTurnsDefault(size, std::vector<char>(size,' '));
    turns= arrTurnsDefault;
}

void Model::fixIResult(const std::string &name, const char &sele, const int &i){
    if(sele == 'W') users[name].setWin(i);
    else if(sele == 'L') users[name].setLoss(i);
    else if(sele == 'D') users[name].setDraw(i);
}

void Model::WriteInfo(User &user){
    std::fstream fileout;
    fileout.open("reportcard.csv", std::ios::out | std::ios::app);
        fileout<<user.getName()<<", "
               <<user.getWin()<<", "
               <<user.getLoss()<<", "
               <<user.getDraw()<<std::endl;
    fileout.close();
}

bool Model::FindFile(std::string name){
    std::fstream fin;
    fin.open("reportcard.csv", std::ios::in);
    std::vector<std::string> row;
    std::string line, word;
    while (fin) {
        row.clear();
        getline(fin, line);
        std::stringstream s(line);
        while (getline(s, word, ',')) {
            row.push_back(word);
        }
        if (row[0] == name) {
            fin.close();
            return true;
        }
    }
    fin.close();
    return false;
}

void Model::LoadInfo(const std::string &name){
    std::fstream fin;
    fin.open("reportcard.csv", std::ios::in);
    std::vector<std::string> row;
    std::string line, word;
    while (fin) {
        row.clear();
        getline(fin, line);
        std::stringstream s(line);
        while (getline(s, word, ',')) {
            row.push_back(word);
        }
        if(row[0] == name){
            this->users[row[0]].setName(row[0]);
            this->users[row[0]].setWin(stoi(row[1]));
            this->users[row[0]].setLoss(stoi(row[2]));
            this->users[row[0]].setDraw(stoi(row[3]));}
    }
    fin.close();
}

void Model::UpdateFile(User &user){
    std::fstream fin, fout;
    fin.open("reportcard.csv", std::ios::in);
    fout.open("reportcardnew.csv", std::ios::out);
    std::string line, word;
    std::vector<std::string> row;
    while (!fin.eof()) {
        row.clear();
        getline(fin, line);
        std::stringstream s(line);
        while (getline(s, word, ',')) {
            row.push_back(word);
        }
        int row_size = row.size();
        if (row[0] == user.getName()) {
            count = 1;
            // the str() converts number into string
            row[1] = std::to_string(user.getWin());
            row[2] = std::to_string(user.getLoss());
            row[3] = std::to_string(user.getDraw());

        }
        if (!fin.eof()) {
            for (int i = 0; i < row_size - 1; i++) {
                fout << row[i] << ", ";
            }

            fout << row[row_size - 1] << "\n";
        }
        else{
            break;
        }
    }
    fin.close();
    fout.close();
    remove("reportcard.csv");
    rename("reportcardnew.csv", "reportcard.csv");
}

void Model::findPlayer(const std::string &name){
    float check;
    std::fstream fin;
    fin.open("reportcard.csv", std::ios::in);
    std::vector<std::string> row;
    std::string line, word;
    while (fin) {
        row.clear();
        getline(fin, line);
        std::stringstream s(line);
        while (getline(s, word, ',')) {
            row.push_back(word);
        }
        if (row[0] == name) {
            check = (float)stoi(row[1])/stoi(row[2]);
            fin.close();
        }
    }
    fin.open("reportcard.csv", std::ios::in);
    while (fin) {
        row.clear();
        getline(fin, line);
        std::stringstream s(line);
        while (getline(s, word, ',')) {
            row.push_back(word);
        }
        if(std::abs((float)stoi(row[1])/stoi(row[2]) - check)){

        }
    }

//    std::map<std::string,User>::iterator i;
//    bool flag = false;
//    float check_temp = 0;
//    float check = (float)users[name].getWin()/users[name].getLoss();
//    for (i = users.begin(); i != users.end(); i++){
//        if((i->second.getName()!=name)&&((((float)i->second.getWin()/i->second.getLoss()) <= check) && (((float)i->second.getWin()/i->second.getLoss()) > check_temp))){
//            check_temp = (float)i->second.getWin()/i->second.getLoss();
//            flag = true;
//        }
//    }
//    if(flag == false){
//        std::cout<<"No have player same level"<<std::endl;
//    }else{
//        std::cout<<"Player same level is:\n";
//        for (i = users.begin(); i != users.end(); i++){
//            if((i->second.getName()!=name)&&(((float)i->second.getWin()/i->second.getLoss()) == check_temp)){
//                std::cout<<i->second.getName()<<std::endl;
//            }
//        }
//    }
}
