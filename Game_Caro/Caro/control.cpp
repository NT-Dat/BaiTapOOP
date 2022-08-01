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

                    ReverseTurn(play);

//                    if(CheckResult()=='X'){
//                        system("cls");
//                        std::cout<<"Player 1 win "<<std::endl;

//                        int i_win = userPlay.getUsers()[name1].getWin();
//                        userPlay.fixIResult(name1, 'W',i_win+1);
//                        int i_loss = userPlay.getUsers()[name2].getLoss();
//                        userPlay.fixIResult(name2, 'L',i_loss+1);
//                        flag = true;
//                    }else if(CheckResult()=='O'){
//                        system("cls");
//                        std::cout<<"Player 2 win "<<std::endl;

//                        int i_win = userPlay.getUsers()[name2].getWin();
//                        userPlay.fixIResult(name2, 'W',i_win+1);

//                        int i_loss = userPlay.getUsers()[name1].getLoss();
//                        userPlay.fixIResult(name1, 'L',i_loss+1);
//                        flag = true;
//                    }else if(CheckResult()=='H') {
//                        system("cls");
//                        std::cout<<"Player 1 and 2 DRAW "<<std::endl;

//                        int i_draw1 = userPlay.getUsers()[name1].getDraw();
//                        userPlay.fixIResult(name1, 'D',i_draw1+1);

//                        int i_draw2 = userPlay.getUsers()[name2].getDraw();
//                        userPlay.fixIResult(name2, 'D',i_draw2+1);
//                        flag = true;
//                    }
                    if(flag == true){
                        this->userPlay.UpdateFile(userPlay.getUsers()[name1]);
                        this->userPlay.UpdateFile(userPlay.getUsers()[name2]);
                        return;
                    }
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
    int count = 1;
    if(col - 1 >= 0 && check[row][col-1] == play){
        count++;
        if(col-2 >= 0 && check[row][col-2] == play){
            count++;
            if(col - 3 >= 0 && check[row][col-3] == play){
                count++;
            }else{
                goto checkright;
            }
        }else{
            goto checkright;
        }
    }else{
        checkright:
        if(col + 1 < check.size() && check[row][col+1] == play){
            count++;
        }
    }
//    for(int i = 0; i <= check.size() - 4; i++){
//        if(check[row][i] == play && check[row][i+1] == play && check[row][i+2] == play && check[row][i+3] == play) return play;
//    }

//    for(int i = 0; i <= check.size() - 4; i++){
//        if(check[i][col] == play && check[i+1][col] == play && check[i+2][col] == play && check[i+3][col] == play) return play;
//    }

//    if(row >= col && (row - col) <= (check.size() - 4)){
//        for(int i = row - col; i <= check.size()-4; i++){
//            if(check[i][i-(row-col)] == play && check[i+1][i+1-(row-col)] == play && check[i+2][i+2-(row-col)] == play && check[i+3][i+3-(row-col)] == play){
//                return play;
//            }
//        }
//    }else if(row < col && (col - row) <= (check.size()-4)){
//        for(int i = col - row; i <= check.size()-4;i++){
//            if(check[i-(col-row)][i] == play && check[i+1-(col-row)][i+1] == play && check[i+2-(col-row)][i+2] == play && check[i+3-(col-row)][i+3] == play){
//                return play;
//            }
//        }
//    }

//    if((row+col) < check.size() && (row + col) >= 3){
//        for(int i = row + col; i <= check.size()-4;i++){
//            if(check[i-(col-row)][i] == play && check[i+1-(col-row)][i+1] == play && check[i+2-(col-row)][i+2] == play && check[i+3-(col-row)][i+3] == play){
//                return play;
//            }
//        }
//    }else if((row+col) >= check.size() && (row + col) <= check.size() + 4){

//    }

//    for(int i =0; i<check.size();i++){
//        for(int j =0; j<check.size();j++){

//            if(check[i][j]=='X'&& check[i][j+1]== 'X' && check[i][j+2] == 'X'&& check[i][j+3] == 'X') return 'X'; // check row
//            else if(check[i][j]=='O'&& check[i][j+1]=='O'&& check[i][j+2] =='O'&& check[i][j+3] =='O') return 'O';

//            if(check[i][j]=='X'&& check[i+1][j]== 'X' && check[i+2][j] == 'X'&& check[i+3][j] == 'X') return 'X';  // check col
//            else if(check[i][j]=='O'&& check[i+1][j]=='O'&& check[i+2][j] =='O'&& check[i+3][j] =='O') return 'O';

//            if(check[i][j+3]=='X'&&check[i+1][j+2] =='X'&&check[i+2][j+1] =='X'&&check[i+3][j] =='X') return 'X';
//            else if(check[i][j+3]=='O'&& check[i+1][j+2] =='O'&& check[i+2][j+1] =='O'&& check[i+3][j] =='O') return 'O';
//            if(check[i][j]=='X'&& check[i+1][j+1]== 'X' && check[i+2][j+2] == 'X'&& check[i+3][j+3] == 'X') return 'X'; // cross
//            else if(check[i][j]=='O'&& check[i+1][j+1]=='O'&& check[i+2][j+2] =='O'&& check[i+3][j+3] =='O') return 'O';

//            if(userPlay.getCount() == userPlay.getSize()*userPlay.getSize()) return 'H';

//        }
//    }
}

void Control::ReverseTurn(char &OX){
    if(OX == 'X') OX ='O';
    else OX = 'X';
}
