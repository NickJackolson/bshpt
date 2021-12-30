/*
Game is the god class which knows about all other classes,
creates user interaction, general management, rule checks,
etc...
*/
#include "../include/game.hpp"

game::game()
{
    this->score[0] = 0;
    this->score[1] = 0;
    this->turn = 0;
}

game::~game(){}

int game::menu()
{
    int option;
    system("clear");
    std::cout << "Battleship" << std::endl;
    std::cout << "1-> Start" << std::endl;
    std::cout << "2-> Quit" << std::endl;
    std::cout << "Enter Option:" << std::endl;
    std::cin >> option;
    return option;
}

void game::placement(int player)
{
    system("clear");
    int i = 0;
    s_coords tailCoord;
    char tempY;
    int tempX;
    int orientation;
    std::cout << "You have 5 ships to place:" << std::endl;
    while(i < 5){
        std::cout << "Place > " << shipNames[i] << " " << shipSizes[i] << std::endl;
        this->playerBoard[player].showShips();
        this->playerBoard[player].showStatus();

        std::cout << "Enter Coords and Orientation (A-I),(0-9),(0-1):" << std::endl;
        scanf(" %c,%d,%d", &tempY, &tempX, &orientation);

        tailCoord.xCoord = tempX;
        tailCoord.yCoord = (int)(tempY - 'A');
        if(this->playerBoard[player].placeOnBoard(i, orientation, tailCoord)){
            i++;
        }else{
            std::cout << "Failed!  Use Valid Range -> (A-I),(0-9),(0-1)" << std::endl;
        }
        system("clear");
    }
}

void game::placeAI()
{
    int i = 0;
    int orientation;
    s_coords tailCoord;
    srand (time(NULL));

    while(i < 5){
        tailCoord.xCoord = rand() % 10;
        tailCoord.yCoord = rand() % 10;
        orientation = rand() % 2;
        if(this->playerBoard[1].placeOnBoard(i, orientation, tailCoord)){
            i++;
        }else{
            continue;
        }
    }
}

void game::battle()
{
    char t;
    char tempY;
    int tempX;
    s_coords targetCoord;

    srand (time(NULL));
    std::cout << "BATTLE!" << std::endl;
    while(this->score[0] < 20 && this->score[1] < 20){
        switch (this->turn)
        {
            case 0:
                std::cout << "Enter Bombing Coords(A-I),(0-9):" << std::endl;
                scanf(" %c,%d", &tempY, &tempX);
                targetCoord.yCoord = (int)(tempY - 'A');
                targetCoord.xCoord = tempX;
                if(this->playerBoard[1].bombard(targetCoord)){
                    std::cout << "HIT" << std::endl;
                    this->score[0]++;
                }
                else
                    std::cout << "MISS" << std::endl;
                break;

            case 1:
                targetCoord.xCoord = rand() % 10;
                targetCoord.yCoord = rand() % 10;
                if(this->playerBoard[0].bombard(targetCoord)){
                    std::cout << "YOU GOT HIT" << std::endl;
                    this->score[1]++;
                }
                else
                    std::cout << "MISS" << std::endl;
                break;

            default:
                break;
        }
        this->turn = (this->turn + 1) % 2;
        this->playerBoard[0].showShips();
        this->playerBoard[0].showStatus();
        std::cout << "PRESS ANY KEY TO ADVANCE TO THE NEXT TURN" << std::endl;
        scanf(" %c", &t);

        system("clear");
    }
    if(this->score[0] > this->score[1])
        std::cout << "YOU WIN" << std::endl;
    else
        std::cout << "YOU LOSE" << std::endl;

}

void game::run()
{
    while(1){
        if(menu() == 1){
            placeAI();
            placement(0);
            battle();
        }else
            break;
    }
}