/*
Game is the god class which knows about all other classes,
creates user interaction, general management, rule checks,
etc...
*/
#include <iostream>

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

void game::placement()
{
    system("clear");
    s_coords tailCoord;
    int tempY;
    int tempX;
    int orientation;
    std::cout << "You have 5 ships to place:" << std::endl;
    for(int i=0;i<5;i++){
        std::cout << "Place > " << shipNames[i] << " " << shipSizes[i] << std::endl;
        this->playerBoard[0].showShips();
        this->playerBoard[0].showStatus();

        std::cout << "Enter Coords (A-I),(0-9):" << std::endl;
        scanf("%d,%d", &tempY, &tempX);

        tailCoord.xCoord = tempX;
        tailCoord.yCoord = tempY % 10;

        std::cout << "Horizontal/Vertical -> 0/1:" << std::endl;
        scanf("%d", &orientation);

        this->playerBoard[0].placeOnBoard(i, orientation, tailCoord);
        system("clear");

        this->playerBoard[0].showShips();
        this->playerBoard[0].showStatus();
        std::cin >> tempY;
    }
}

void game::battle()
{
    int t;
    std::cout << "BATTLE!" << std::endl;
    this->playerBoard[0].showShips();
    this->playerBoard[0].showStatus();
}

void game::run()
{
    while(1){
        if(menu() == 1){
            // placement();
            battle();
        }else
            break;
    }
}