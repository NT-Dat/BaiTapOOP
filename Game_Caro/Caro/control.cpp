#include "control.h"

Model Control::getUser(){
    return this->userPlay;
}

void Control::CreateUser(){
    try{
        //system("cls");
        std::string name;
        std::cout << "Enter user name:"; std::cin.ignore(); getline(std::cin, name);
        Exception::InvalidNameException(name);
        User user(name);
        userPlay.CreateUser(user);
    }catch(const char* msg){
        std::cout << msg;
        Control::CreateUser();
    }
}

void Control::StartGame(){
    bool flag = false;
    char play = 'X';
    int row, col;
    char opt;
    data replay;
    this->replay.clear();
    std::cout<<"Enter name user 1:";     //Default play X
    std::string name1;
    std::cin>>name1;
    if(this->userPlay.FindFile(name1) == false){
        std::cout << "Not find "  << name1 << "\n";

        return;
    }
    this->userPlay.LoadInfo(name1);
    std::cout<<"Enter name user 2:";     //Default play O
    std::string name2;
    std::cin>>name2;
    if(this->userPlay.FindFile(name2) == false){
        std::cout << "Not find "  << name2 << "\n";

        return;
    }
    this->userPlay.LoadInfo(name2);
    std::cout<<"Enter size Board:";
    int size;
    std::cin>>size;

    userPlay.setSize(size);
    userPlay.createArrModel2D();
    replay.size = size;
    system("cls");
    views.displayBoard(size);

    INPUT_RECORD ir[128];
    HANDLE       hStdInput  = NULL;
    HANDLE       hStdOutput = NULL;
    HANDLE       hEvent     = NULL;
    DWORD        nRead;
    COORD        xy;

    hStdInput=GetStdHandle(STD_INPUT_HANDLE);
    hStdOutput=GetStdHandle(STD_OUTPUT_HANDLE);
    //cls(hStdOutput);
    SetConsoleMode(hStdInput,ENABLE_ECHO_INPUT|ENABLE_LINE_INPUT|ENABLE_MOUSE_INPUT|ENABLE_EXTENDED_FLAGS);
    FlushConsoleInputBuffer(hStdInput);
    hEvent=CreateEvent(NULL,FALSE,FALSE,NULL);
    HANDLE handles[2] = {hEvent, hStdInput};
    while(WaitForMultipleObjects(2,handles,FALSE,INFINITE)){
        ReadConsoleInput(hStdInput,ir,128,&nRead);
        for(size_t i=0;i<nRead;i++){
            if(ir[i].EventType == MOUSE_EVENT) {
                xy.X=0, xy.Y=1;
                SetConsoleCursorPosition(hStdOutput,xy);
                if((GetKeyState(VK_LBUTTON) & 0x8000) != 0){
                    col = ir[i].Event.MouseEvent.dwMousePosition.X/2;
                    row = ir[i].Event.MouseEvent.dwMousePosition.Y/2;

                    if(CheckValid(row, col)){
                        Graphics::gotoXY(50,0);
                        std::cout<<" turn unvalid!!!";
                        break;
                    }

                    userPlay.addTurn(row, col, play);

                    views.displayOX(row, col, play);

                    replay.row = row;
                    replay.col = col;
                    replay.XO = play;
                    this->replay.push_back(replay);

                    if(CheckResult(row, col, play)==play){
                        if(play == 'X'){
                            system("cls");
                            std::cout<<"Player 1 win "<<std::endl;
                            int i_win = userPlay.getUsers()[name1].getWin();
                            userPlay.fixIResult(name1, 'W',i_win+1);
                            int i_loss = userPlay.getUsers()[name2].getLoss();
                            userPlay.fixIResult(name2, 'L',i_loss+1);
                            flag = true;
                        }else{
                            system("cls");
                            std::cout<<"Player 2 win "<<std::endl;

                            int i_win = userPlay.getUsers()[name2].getWin();
                            userPlay.fixIResult(name2, 'W',i_win+1);

                            int i_loss = userPlay.getUsers()[name1].getLoss();
                            userPlay.fixIResult(name1, 'L',i_loss+1);
                            flag = true;
                        }
                    }else if(CheckResult(row, col, play)=='H'){
                        system("cls");
                        std::cout<<"Player 1 and 2 DRAW "<<std::endl;

                        int i_draw1 = userPlay.getUsers()[name1].getDraw();
                        userPlay.fixIResult(name1, 'D',i_draw1+1);

                        int i_draw2 = userPlay.getUsers()[name2].getDraw();
                        userPlay.fixIResult(name2, 'D',i_draw2+1);
                        flag = true;
                    }

                    if(flag == true){
                        this->userPlay.UpdateFile(userPlay.getUsers()[name1]);
                        this->userPlay.UpdateFile(userPlay.getUsers()[name2]);
                        return;
                    }

                    ReverseTurn(play);

                }

            }
        }
    }

}

void Control::Show(){
    std::cout<<"Enter name need show:";
    std::string name;
    std::cin>>name;
    userPlay.LoadInfo(name);
    userPlay.ShowUser(name);
}

void Control::Find(){
    std::cout<<"Enter name need find player same level:";
    std::string name;
    std::cin>>name;
    userPlay.findPlayer(name);
}

bool Control::CheckValid(const int &row,const int &col){
    if(row>userPlay.getSize()||col>userPlay.getSize()) return true;
    else if(userPlay.getTurn()[row][col] != ' ') return true;
    else return false;
}
char Control::CheckResult(const int &row,const int &col, char &play){
    std::vector<std::vector <char>> check = userPlay.getTurn();
    for(int i = col, j = col, count = 1, flag = 1, flag2 = 0; i >= 0 && j < check.size();){
        if(flag){
            if((i - 1 >= 0) && (check[row][i-1] == play)){
                count++;
                if(count == 5){
                    if((i - 2 >= 0) && (check[row][i-2] == play || check[row][i-2] == ' ')){
                        return play;
                    }else{
                        flag = 0;
                        flag2 = 1;
                    }
                }
                i--;
            }else{
                if((i - 1 >= 0) && (check[row][i-1] != ' ')){
                    flag2 = 1;
                }
                flag = 0;
            }
        }else{
            if(count == 5){
                if((j + 1 < check.size()) && (check[row][j+1] == play || check[row][j+1] == ' ')){
                    return play;
                }else{
                    if(flag2 == 0){
                        return play;
                    }
                    break;
                }
            }else{
                if((j + 1 < check.size()) && (check[row][j+1] == play)){
                    count++;
                    j++;
                }else{
                    break;
                }
            }
        }
    }

    for(int i = row, j = row, count = 1, flag = 1, flag2 = 0; i >= 0 && j < check.size();){
        if(flag){
            if((i - 1 >= 0) && (check[i - 1][col] == play)){
                count++;
                if(count == 5){
                    if((i - 2 >= 0) && (check[i - 2][col] == play || check[i - 2][col] == ' ')){
                        return play;
                    }
                    else{
                        flag = 0;
                        flag2 = 1;
                    }
                }
                i--;
            }else{
                if((i - 1 >= 0) && (check[i - 1][col] != ' ')){
                    flag2 = 1;
                }
                flag = 0;
            }
        }else{
            if(count == 5){
                if((j + 1 < check.size()) && (check[j+1][col] == play || check[j+1][col] == ' ')){
                    return play;
                }else{
                    if(flag2 == 0){
                        return play;
                    }
                    break;
                }
            }else{
                if((j + 1 < check.size()) && (check[j+1][col] == play)){
                    count++;
                    j++;
                }else{
                    break;
                }
            }
        }
    }

    for(int i1 = row, i2 = row, j1 =col, j2 = col, count = 1, flag = 1, flag2 = 0; i1 >= 0 && j1 >= 0  && i2 < check.size() && j2 < check.size();){
        if(flag){
            if((i1 - 1 >= 0) && (j1 - 1 >= 0) && (check[i1 - 1][j1 - 1] == play)){
                count++;
                if(count == 5){
                    if((i1 - 2 >= 0) && (j1 - 2 >= 0) && (check[i1 - 2][j1 - 2] == play || check[i1 - 2][j1 - 2] == ' ')){
                        return play;
                    }else{
                        flag = 0;
                        flag2 = 1;
                    }
                }
                i1--;
                j1--;
            }else{
                if((i1 - 1 >= 0) && (j1 - 1 >= 0) && (check[i1 - 1][j1 - 1] != ' ')){
                    flag2 = 1;
                }
                flag = 0;
            }
        }else{
            if(count == 5){
                if((i2 + 1 < check.size()) && (j2 + 1 < check.size()) && (check[i2 + 1][j2 + 1] == play || check[i2 + 1][j2 + 1] == ' ')){
                    return play;
                }else{
                    if(flag2 == 0){
                        return play;
                    }
                    break;
                }
            }else{
                if((i2 + 1 < check.size()) && (j2 + 1 < check.size()) && (check[i2 + 1][j2 + 1] == play)){
                    count++;
                    i2++;
                    j2++;
                }else{
                    break;
                }
            }
        }
    }

    for(int i1 = row, i2 = row, j1 =col, j2 = col, count = 1, flag = 1, flag2 = 0; i1 >= 0 && j2 >= 0  && i2 < check.size() && j1 < check.size();){
        if(flag){
            if((i1 - 1 >= 0) && (j1 + 1 < check.size()) && (check[i1 - 1][j1+1] == play)){
                count++;
                if(count == 5){
                    if((i1 - 2 >= 0) && (j1 + 2 < check.size()) && (check[i1 - 2][j1+2] == play || check[i1 - 2][j1+2] == ' ')){
                        return play;
                    }else{
                        flag = 0;
                        flag2 = 1;
                    }
                }
                i1--;
                j1++;
            }else{
                if((i1 - 1 >= 0) && (j1 + 1 < check.size()) && (check[i1 - 1][j1+1] != ' ')){
                    flag2 = 1;
                }
                flag = 0;
            }
        }else{
            if(count == 5){
                if((j2 - 1 >= 0) && (i2 + 1 < check.size()) && (check[i2 + 1][j2-1] == play || check[i2 + 1][j2-1] == ' ')){
                    return play;
                }else{
                    if(flag2 == 0){
                        return play;
                    }
                    break;
                }
            }else{
                if((j2 - 1 >= 0) && (i2 + 1 < check.size()) && (check[i2 + 1][j2-1] == play)){
                    count++;
                    i2++;
                    j2--;
                }else{
                    break;
                }
            }
        }
    }

    if(userPlay.getCount() == userPlay.getSize()*userPlay.getSize()) return 'H';
}

void Control::ReverseTurn(char &OX){
    if(OX == 'X') OX ='O';
    else OX = 'X';
}

void Control::Replay(){
    system("cls");
    views.displayBoard(this->replay[0].size);
    for(auto x : this->replay){
        views.displayOX(x.row, x.col, x.XO);
        Sleep(500);
    }
    Graphics::gotoXY(50,0);
}
