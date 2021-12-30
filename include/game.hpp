#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <cassert>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>

#include "board.hpp"

class game
{
private:
    board playerBoard[2];
    int score[2];
    int turn;
    int menu();
    void placement(int player);
    void battle();
    void placeAI();

public:
    game();
    ~game();
    void run();
};
#endif