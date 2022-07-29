#ifndef PLAYER_H
#define PLAYER_H

#include <string.h>
#include <sstream>
#include <iostream>

using namespace std;

class Player
{
private:
    string _name;
    int _step;
    int _win;
    int _lose;
    int _draw;
public:
    Player();
    string GetName();
    void SetName(string);
    void Input();
    void IncreStep();
    void DecreStep() { _step--; }
    int GetStep();
    void SetStep(int value) { _step = value; }
    void InitStep() { _step = 0; }
    void SetWin(int value) { _win = value; }
    void SetLose(int value) { _lose = value; }
    void SetDraw(int value) { _draw = value; }
    int GetWin() { return _win; }
    int GetLose() { return _lose; }
    int GetDraw() { return _draw; }
    void IncreWin() { _win++; }
    void IncreLose() { _lose++; }
    void IncreDraw() { _draw++; }
};

#endif // PLAYER_H
