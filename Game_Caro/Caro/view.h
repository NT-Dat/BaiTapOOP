#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include "graphics.h"

class View{

public:
    View();
    ~View();

    void displayBoard(const int &size);
    void displayOX(const int &row, const int &col, const char &OX);
};

#endif // VIEW_H
