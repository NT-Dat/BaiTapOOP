#include "graphics.h"

Graphics::Graphics()
{

}

void Graphics::gotoXY(int pX, int pY)
{
    COORD coord;
    coord.X = pX;
    coord.Y = pY;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Graphics::fixConsoleWindow()
{
    HWND consoleWindow = GetConsoleWindow();
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
    style = style & ~(WS_MAXIMIZEBOX)& ~(WS_THICKFRAME);
    SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void Graphics::TextColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void Graphics::Nocursortype()
{
    CONSOLE_CURSOR_INFO Info;
    Info.bVisible = FALSE;
    Info.dwSize = 20;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

void Graphics::UnNocursortype()
{
    CONSOLE_CURSOR_INFO Info;
    Info.bVisible = TRUE;
    Info.dwSize = 20;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

void Graphics::cls(HANDLE hStdOut){
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    COORD coordScreen = {0,0};
    DWORD cCharsWritten;
    DWORD dwConSize;

    GetConsoleScreenBufferInfo(hStdOut, &csbi);
    dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    FillConsoleOutputCharacter(hStdOut,(TCHAR)' ',dwConSize,coordScreen,&cCharsWritten);
    GetConsoleScreenBufferInfo(hStdOut,&csbi);
    FillConsoleOutputAttribute(hStdOut,csbi.wAttributes,dwConSize,coordScreen,&cCharsWritten);
    SetConsoleCursorPosition(hStdOut,coordScreen);

    return;
}
