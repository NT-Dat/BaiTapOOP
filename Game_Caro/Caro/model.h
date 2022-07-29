#ifndef MODEL_H
#define MODEL_H

#include "user.h"
#include <map>
#include <fstream>
#include <sstream>
#include <string.h>
#include <vector>

class Model{
private:
    int size;       // size Board
    int count = 0;  // number turn
    std::map<std::string,User>  users;    // manager Player
    std::vector<std::vector <char>> turns;    // create arr board


public:
    Model();
    ~Model();

    int getSize();
    void setSize(const int &size);

    int getCount();

    std::map<std::string,User> getUsers();

    std::vector<std::vector<char>> getTurn();

    void CreateUser(User &user);
    void ShowUser(const std::string &name);

    void addTurn(const int &row, const int &col, const char OX);

    void createArrModel2D();
    void fixIResult(const std::string &name, const char &sele, const int &i);

    void WriteInfo(User &user);
    void LoadInfo(const std::string& name);
    bool FindFile(std::string name);
    void UpdateFile(User &user);

    void findPlayer(const std::string &name);

};

#endif // MODEL_H
