#include "control.h"

int main(){
    Graphics::fixConsoleWindow();
    Graphics::TextColor(10);
    Control control;
    while (true) {
        system("cls");
        std::cout<<"Enter 1: To create player"<<std::endl;
        std::cout<<"Enter 2: To playgame "<<std::endl;
        std::cout<<"Enter 3: To show infor"<<std::endl;
        std::cout<<"Enter 4: To find player same level"<<std::endl;
        std::cout<<"Enter 5: To exit."<<std::endl;

        int select;
        std::cin >> select;

        switch (select) {
        case 1: {
            control.CreateUser();
            break;
        }
        case 2: {
            control.StartGame();
            break;
        }
        case 3: {
            control.Show();
            break;
        }

        case 4: {
            control.Find();
            break;
        }

        case 5:
            return 0;

        default:
            std::cout<<"Invalid"<<std::endl;
            continue;
        }
        std::cout << "Enter 0 to back\n";
        std::cin >> select;
    }

    return 0;

}
