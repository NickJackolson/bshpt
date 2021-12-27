#ifndef SHIP_HPP
#define SHIP_HPP

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct s_coords{
    int xCoord;
    int yCoord;
    bool hit;
};

class ship
{
private:
    int id;
    int size;
    char *name;
    bool placed;
    bool floating;
    struct s_coords *coords;
public:
    ship();
    ship(int id, int size, const char* name);
    ~ship();
    void place(struct s_coords *coords);
    bool hit(struct s_coords coord);
    bool isFloating();
    char* getName();
    int getSize();
};
#endif