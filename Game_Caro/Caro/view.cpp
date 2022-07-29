#include "view.h"

View::View(){}
View::~View(){}

void View::displayBoard(const int &size){
    for (int i = 0; i < 2*size; ++i)
    {
        for (int j = 0; j <=2*size ; ++j)
        {
            Graphics::gotoXY(j,i);
            if (i % 2 == 1)
            {
                std::cout<<"--";
            }
            else
            {
                if (j % 2 == 1)
                {
                    std::cout<<"  ";
                }
                else
                {
                    std::cout<<"| ";
                }
            }
        }
    }

}

void View::displayOX(const int &row, const int &col,const char &OX){
    Graphics::gotoXY(2*col+1, 2*row);
    std::cout<<OX;
}

