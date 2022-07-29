#include "_board.h"

_Board::_Board()
{
    _size = 0;
    _left = 0;
    _top = 0;
    _pArr = NULL;
}

_Board::_Board(int pSize, int pX, int pY)
{
    _size = pSize;
    _left = pX;
    _top = pY;
    _pArr = new _Point*[pSize];
    for (int i = 0; i < pSize; i++) _pArr[i] = new _Point[pSize];
}

_Board::~_Board()
{

    for (int i = 0; i < _size; i++) delete[] _pArr[i];
        delete[] _pArr;
}

int _Board::getSize(){ return _size; }

int _Board::getLeft(){ return _left; }

int _Board::getTop(){ return _top; }

int _Board::getXAt(int i, int j) { return _pArr[i][j].getX(); }

int _Board::getYAt(int i, int j) { return _pArr[i][j].getY(); }

void _Board::resetData()
{
    if (_size == 0) return; // Phải gọi constructor trước khi resetData
    for (int i = 0; i < _size; i++)
    {
        for (int j = 0; j < _size; j++)
        {
            _pArr[i][j].setX(4 * j + _left + 2); // Trùng với hoành độ màn hình bàn cờ
            _pArr[i][j].setY(2 * i + _top + 1); // Trùng với tung độ màn hình bàn cờ
            _pArr[i][j].setCheck(0);
        }
    }
}

void _Board::Init(int i,int j, int value)
{
    if (_size == 0) return; // Phải gọi constructor trước khi resetData

    _pArr[i][j].setX(4 * j + _left + 2); // Trùng với hoành độ màn hình bàn cờ
    _pArr[i][j].setY(2 * i + _top + 1); // Trùng với tung độ màn hình bàn cờ
    _pArr[i][j].setCheck(value);
}

void _Board::drawBoard()
{
    if (_pArr == NULL) return; // phải gọi constructor trước

    _Common::gotoXY(_left + 4 * _size + 10, 0);
    for (int i = _left + 4 * _size + 10; i <= _left + 4 * _size + 60; i++)
    {
        if (i == _left + 4 * _size + 10) putchar(201);
        else if (i == _left + 4 * _size + 60) putchar(187);
        else putchar(205);
    }
    for (int i = 1; i <= 6; i++)
    {
        _Common::gotoXY(_left + 4 * _size + 10, i); putchar(186);
        _Common::gotoXY(_left + 4 * _size + 60, i); putchar(186);
    }
    _Common::gotoXY(_left + 4 * _size + 10, 6);
    for (int i = _left + 4 * _size + 10; i <= _left + 4 * _size + 60; i++)
    {
        if (i == _left + 4 * _size + 10) putchar(200);
        else if (i == _left + 4 * _size + 60) putchar(188);
        else putchar(205);
    }

    _Common::gotoXY(_pArr[0][0].getX(), _pArr[0][0].getY());// di chuyển vào ô đầu
}

int _Board::GetXO(int x, int y)
{
    return _pArr[x][y].getCheck();
}

int _Board::checkBoard(int pX, int pY, bool pTurn)
{
    for (int i = 0; i < _size; i++)
    {
        for (int j = 0; j < _size; j++)
        {
            if (_pArr[i][j].getX() == pX && _pArr[i][j].getY() == pY && _pArr[i][j].getCheck() == 0)
            {
                if (pTurn) _pArr[i][j].setCheck(-1);// Nếu lượt hiện hành là true: c = -1
                else _pArr[i][j].setCheck(1);// Nếu lượt hiện hành là false: c = 1
                return _pArr[i][j].getCheck();
            }
        }
    }
    return 0;
}



int _Board::Undo(int pX, int pY)
{
    int res;
    for (int i = 0; i < _size; i++)
    {
        for (int j = 0; j < _size; j++)
        {
            if (_pArr[i][j].getX() == pX && _pArr[i][j].getY() == pY && _pArr[i][j] .getCheck()!= 0)
            {
                res = _pArr[i][j].getCheck();
                _pArr[i][j].setCheck(0);
                return res;
            }
        }
    }
    return 0;
}

int _Board::testBoard(int& pX,int& pY)
{
    // Xu ly hoa
    bool check = true;
    for (int i = 0; i < _size; i++)
    {
        for (int j = 0; j < _size; j++)
        {
            if (_pArr[i][j].getCheck() == 0)
            {
                check = false;
                break;
            }
        }
    }
    if (check) return 0;

    //Xu ly thang/thua
    int x, y = 0;

    for (int i = 0; i < _size; i++)
    {
        for (int j = 0; j < _size; j++)
        {
            if (_pArr[i][j].getX() == pX && _pArr[i][j].getY() == pY)
            {
                x = i;
                y = j;
                break;
            }
        }
    }

    int res = 0;
    int xStart = (x - 4 > 0) ? x - 4 : 0;
    int yStart = (y - 4 > 0) ? y - 4 : 0;

    int xEnd = (x + 4 >= _size) ? _size - 1 : x + 4;
    int yEnd = (y + 4 >= _size) ? _size - 1 : y + 4;

    int x1, x2, y1, y2;

    for (int i = xStart; i <= x; i++)
    {
        if (i + 4 < _size)
        {
            res = _pArr[i][y].getCheck() + _pArr[i + 1][y].getCheck() + _pArr[i + 2][y].getCheck()
                + _pArr[i + 3][y].getCheck() + _pArr[i + 4][y].getCheck();

            x1 = i - 1 >= 0 ? i - 1 : xStart;
            y1 = y;

            x2 = i + 5 >= _size ? x + 4 : i + 5;
            y2 = y;
        }

        if (res == 5 && (_pArr[x1][y1].getCheck() != -1 || _pArr[x2][y2].getCheck() != -1))
        {
            pX = i;
            pY = y;
            return 1;
        }
        if (res == -5 && (_pArr[x1][y1].getCheck() != 1 || _pArr[x2][y2].getCheck() != 1))
        {
            pX = i;
            pY = y;
            return -1;
        }
    }

    for (int i = yStart; i <= y; i++)
    {
        if (i + 4 < _size)
        {
            res = _pArr[x][i].getCheck() + _pArr[x][i + 1].getCheck() + _pArr[x][i + 2].getCheck()
                + _pArr[x][i + 3].getCheck() + _pArr[x][i + 4].getCheck();

            x1 = x;
            y1 = i - 1 >= 0 ? i - 1 : yStart;

            x2 = x;
            y2 = i + 5 >= _size ? y + 4 : i + 5;
        }

        if (res == 5 && (_pArr[x1][y1].getCheck() != -1 || _pArr[x2][y2].getCheck() != -1))
        {
            pX = x;
            pY = i;
            return 1;
        }
        if (res == -5 && (_pArr[x1][y1].getCheck() != 1 || _pArr[x2][y2].getCheck() != 1))
        {
            pX = x;
            pY = i;
            return -1;
        }
    }

    for (int i = xStart; i <= x; i++)
    {
        for (int j = yStart; j <= y; j++)
        {
            if (i - j == x - y && i + 4 < _size &&j + 4 < _size)
            {
                res = _pArr[i][j].getCheck() + _pArr[i + 1][j + 1].getCheck() + _pArr[i + 2][j + 2].getCheck()
                    + _pArr[i + 3][j + 3].getCheck() + _pArr[i + 4][j + 4].getCheck();
                x1 = i - 1;
                y1 = j - 1;
                if (x1 < 0 || y1 < 0)
                {
                    x1 = i;
                    y1 = j;
                }
                x2 = i + 5;
                y2 = j + 5;
                if (x2 >= _size || y2 >= _size)
                {
                    y2 = j;
                    x2 = i;
                }
            }

            if (res == 5 && (_pArr[x1][y1].getCheck() != -1 || _pArr[x2][y2].getCheck() != -1))
            {
                pX = i;
                pY = j;
                return 1;
            }
            if (res == -5 && (_pArr[x1][y1].getCheck() != 1 || _pArr[x2][y2].getCheck() != 1))
            {
                pX = i;
                pY = j;
                return -1;
            }
        }
    }

    for (int i = xEnd; i >= x; i--)
    {
        for (int j = yStart; j <= y; j++)
        {
            if (i + j == x + y && j + 4 < _size && i - 4 >= 0)
            {
                res = _pArr[i][j].getCheck() + _pArr[i - 1][j + 1].getCheck() + _pArr[i - 2][j + 2].getCheck()
                    + _pArr[i - 3][j + 3].getCheck() + _pArr[i - 4][j + 4].getCheck();
                x1 = i + 1;
                y1 = j - 1;
                if (x1 >= _size || y1<0)
                {
                    x1 = i;
                    y1 = i;
                }
                x2 = i - 5;
                y2 = j + 5;
                if (x2<0 || y2>_size)
                {
                    x2 = i;
                    y2 = j;
                }
            }
            if (res == 5 && (_pArr[x1][y1].getCheck() != -1 || _pArr[x2][y2].getCheck() != -1))
            {
                pX = i;
                pY = j;
                return 1;
            }
            if (res == -5 && (_pArr[x1][y1].getCheck() != 1 || _pArr[x2][y2].getCheck() != 1))
            {
                pX = i;
                pY = j;
                return -1;
            }
        }
    }

    return 2; // Trả mặc định là tiep tuc
}
