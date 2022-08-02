#ifndef CONTROL_H
#define CONTROL_H

#include "model.h"
#include "view.h"
#include "graphics.h"
#include "exception.h"

struct data{
    int row;
    int col;
    int size;
    char XO;
};

class Control{
private:
    Model userPlay;
    View views;
    std::vector<data> replay;
public:
    Model getUser();
    void CreateUser();
    void StartGame();
    void Show();
    void Find();
    bool CheckValid(const int &row,const int &col);
    char CheckResult(const int &row,const int &col, char &play);
    void ReverseTurn(char &OX);
    void Replay();
};

#endif // CONTROL_H
