#ifndef _BOARD_H
#define _BOARD_H

#include "_point.h"
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include "_common.h"

using namespace std;

struct Move
{
    int row, col;
};

class _Board
{
private:
    int _size;
    int _left, _top;
    _Point** _pArr;
public:
    _Board();
    _Board(int, int, int);
    ~_Board();
    int getSize();
    int getLeft();
    int getTop();
    int getXAt(int, int);
    int getYAt(int, int);
    void resetData();
    void drawBoard();
    int checkBoard(int, int, bool);
    int testBoard(int&, int&);
    int Undo(int, int);
    int GetXO(int, int);
    void Init(int, int, int);
};

#endif // _BOARD_H
