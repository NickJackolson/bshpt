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
        printf("coords : %d(%c), %d, %d\n",(int)(tempY - 'A'), tempY, tempX, orientation);
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
    int t;
    std::cout << "BATTLE!" << std::endl;
    std::cout << "PLAYER:" << std::endl;
    this->playerBoard[0].showShips();
    this->playerBoard[0].showStatus();
    std::cout << "AI:" << std::endl;
    this->playerBoard[1].showShips();
    this->playerBoard[1].showStatus();
    std::cout << "Press Any Key to return to Menu:" << std::endl;
    std::cin >> t;
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