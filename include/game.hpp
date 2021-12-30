#ifndef GAME_HPP
#define GAME_HPP

#include "board.hpp"

class game
{
private:
    board playerBoard[2];
    int score[2];
    int turn;
    int menu();
    void placement();
    void battle();

public:
    game();
    ~game();
    void run();
};
#endif