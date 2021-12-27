#ifndef BOARD_HPP
#define BOARD_HPP

#include <stdio.h>

#include "./ship.hpp"

enum {VERTICAL, HORIZONTAL};
enum {DESTROYER, SUBMARINE, CRUISER, BATTLESHIP, CARRIER};

// The 5 ships: Carrier(5), Battleship(4), Cruiser(3), Submarine(3), and Destroyer(2).
// Board tile status: water(0), ship(1), hit(2)
class board
{
private:
    ship fleet[5];
    int **table;

public:
    board();
    ~board();
    bool placeOnBoard(int shipKind, int orientation, struct s_coords center);
    bool bombard(struct s_coords target);
    void showStatus();
    void showShips();
};
#endif