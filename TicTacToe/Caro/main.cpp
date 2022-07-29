#include <iostream>
#include<windows.h>
#include "_common.h"
#include "_board.h"
#include "_game.h"
#include "_point.h"
#include <stdio.h>
#include <conio.h>
#include <fstream>
using namespace std;

#define BOARD_SIZE 1
#define LEFT 1
#define TOP 1

void NewGame(void);

_Game g(BOARD_SIZE, LEFT, TOP);

int main()
{
    _Common::fixConsoleWindow();
    g.Turn(true);
    _Common::gotoXY(40, 10);
    fflush(stdin);
    cout << "Name Player 1 : ";
    g.GetUser1().Input();
    _Common::gotoXY(40, 12);
    fflush(stdin);
    cout << "Name Player 2 : ";
    g.GetUser2().Input();
    g.Init(BOARD_SIZE, LEFT, TOP);
    g.startGame();
    g.Turn(true);
    NewGame();
    system("pause");
}

void NewGame()
{
    bool init = true;
    bool turn = g.GetTurn();
    bool options = g.GetOptions();
    g.SetLoop(true);
    int cur = -1;
    int *x = new int[BOARD_SIZE*BOARD_SIZE];
    int *y = new int[BOARD_SIZE*BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE*BOARD_SIZE; i++)
    {
        x[i] = -1;
        y[i] = -1;
    }

    while (g.isContinue())
    {
        int key = g.processFinishTime();
        switch (key)
        {
        case -1: case 1: case 0:
            if (g.askContinue() != 'Y') g.exitGame();
            else
            {
                system("cls");
                //g.Init(BOARD_SIZE, LEFT, TOP);
                g.SetLoop(true);
                g.waitKeyBoard();
                g.GetUser1().InitStep();
                g.GetUser2().InitStep();
                g.SetX(LEFT);
                g.SetY(TOP);
                g.startGame();
                g.Turn(turn);
                NewGame();
                g.exitGame();
            }
        }
    }

    g.waitKeyBoard();
    if (g.getCommand() == 27) g.exitGame();
    else
    {
        switch (g.getCommand())
        {
        case 59:
            system("cls");
            g.Init(BOARD_SIZE, LEFT, TOP);
            g.startGame();
            g.Turn(turn);
            NewGame();
            break;
        case 62:
            if (cur >= 0 && x[cur] >= 0 && y[cur] >= 0)
            {
                g.Undo(x[cur], y[cur]);
                x[cur] = -1;
                y[cur] = -1;
                cur--;
            }
            g.ShowInfor();
            break;
        case 'A': case 75:
            g.moveLeft();
            break;
        case 'W': case 72:
            g.moveUp();
            break;
        case 'S': case 80:
            g.moveDown();
            break;
        case 'D': case 77:
            g.moveRight();
            break;
        case 13: case 32:

            //Đánh dấu bàn cờ, sau đó kiểm tra và xử lý thắng/thua/hòa/tiếp tục
            if (g.processCheckBoard())
            {
                cur++;
                x[cur] = g.GetX();
                y[cur] = g.GetY();

                int key = g.processFinish();
                switch (key)
                {
                case -1: case 1: case 0:
                    if (g.askContinue() != 'Y') g.exitGame();
                    else
                    {
                        system("cls");
                        //g.Init(BOARD_SIZE, LEFT, TOP);
                        g.SetLoop(true);
                        g.waitKeyBoard();
                        g.GetUser1().InitStep();

                        g.GetUser2().InitStep();

                        g.SetX(LEFT);
                        g.SetY(TOP);
                        g.startGame();
                        g.Turn(turn);
                        NewGame();
                        g.exitGame();
                    }
                }
            }
            g.ShowInfor();
            break;
        }
    }
    //Sleep(50);
}

