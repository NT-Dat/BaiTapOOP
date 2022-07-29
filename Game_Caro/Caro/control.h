#ifndef CONTROL_H
#define CONTROL_H

#include "model.h"
#include "view.h"
#include "graphics.h"
#include "exception.h"

class Control{
private:
    Model userPlay;
    View views;
public:
    Model getUser();
    void CreateUser();
    void StartGame();
    void Show();
    void Find();
    bool CheckValid(const int &row,const int &col);
    char CheckResult(const int &row,const int &col, char &play);
    void ReverseTurn(char &OX);
};

#endif // CONTROL_H
