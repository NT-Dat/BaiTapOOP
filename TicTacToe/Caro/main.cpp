#include <iostream>
using namespace std;

class TicTacToe
{
private:
    char board[3][3];
public:
    TicTacToe();
    void DrawBoard();
    void PrintBoard();
    void GetMove(const char& player);
    void TogglePlayer(char& player);
    bool DetermineDraw(char& playerWin);
};

TicTacToe::TicTacToe()
{
     for (int i = 0; i < 9; i++)
         board[i / 3][i % 3] = '1' + i;
}

void TicTacToe::DrawBoard()
{
    system("cls");
    cout <<"\tWelcome to the Classes Tic Tac Toe! \n";

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}


void TicTacToe::GetMove(const char& player)
{
    int move;
    cout <<"\nEnter the number of the field you would like to move:\n";
    cin >> move;
    for(int i = 1; i <= 9; i++){
        if(move == i){
            i--;
            board[i/3][i%3] = player;
            break;
        }
    }
}

void TicTacToe::TogglePlayer(char& player)
{
    if (player == 'X')
        player = 'O';
    else if(player == 'O')
        player = 'X';
}

bool TicTacToe::DetermineDraw(char& playerWin)
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if((board[i][0] == board[i][1] && board[i][1] == board[i][2]) || (board[0][j] == board[1][j] && board[1][j] == board[2][j])){
                if(board[i][0] == 'X'){
                    playerWin = 'X';
                }else{
                    playerWin = 'Y';
                }
                return true;
            }
        }
    }
    return false;
}

int main()
{
    TicTacToe game;
    char player = 'X';
    char playerWin = 'X';
    while(game.DetermineDraw(playerWin) == false)
    {
        game.DrawBoard();
        game.GetMove(player);
        game.TogglePlayer(player);
    }
    game.DrawBoard();
    if(playerWin == 'X'){
        cout << "\nX win";
    }else{
        cout << "\nY win";
    }
    system("pause");
}
