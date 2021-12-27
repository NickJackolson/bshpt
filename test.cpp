#include <iostream>

#include "./include/game.hpp"
#include "./include/ship.hpp"
#include "./include/board.hpp"

int main(int argc, char const *argv[])
{
    board gameBoard = board();
    struct s_coords cord;
    cord.xCoord = 9;
    cord.yCoord = 4;
    if(gameBoard.placeOnBoard(CARRIER, HORIZONTAL, cord)){
        std::cout << "Ship Placed" << std::endl;
    }
    gameBoard.showStatus();
    gameBoard.showShips();

    cord.xCoord = 0;
    cord.yCoord = 0;
    std::cout << "1st Bombing" << std::endl;
    if(gameBoard.bombard(cord)){
        std::cout << "Ship Hit" << std::endl;
    }
    cord.xCoord = 9;
    cord.yCoord = 4;
    std::cout << "2nd Bombing" << std::endl;
    for(int i=0;i<5;i++){
        if(gameBoard.bombard(cord))
            std::cout << "Ship Hit" << std::endl;
        cord.xCoord--;
    }
    gameBoard.showShips();
    gameBoard.showStatus();

    return 0;
}
