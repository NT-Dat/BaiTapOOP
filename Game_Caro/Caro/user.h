#ifndef USER_H
#define USER_H

#include <iostream>

class User{
private:
    std::string name;
    int win;
    int loss;
    int draw;

public:
    User();
    ~User();
    User(const std::string &name);

    std::string getName();
    void setName(const std::string &name);

    int getWin();
    void setWin(const int &win);

    int getLoss();
    void setLoss(const int &loss);

    int getDraw();
    void setDraw(const int &draw);

    void ShowInfo();

};

#endif // USER_H
