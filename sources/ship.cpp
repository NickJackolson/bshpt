#include "../include/ship.hpp"
#include <string.h>
#include <stdlib.h>

ship::ship(){}

ship::ship(int id, int size, char* name)
{
    this->id = id;
    this->size = size;
    strcpy(this->name, name);
    this->coords = (struct s_coords*) malloc(sizeof(struct s_coords)*size);
}

ship::~ship()
{
    free(this->name);
    free(this->coords);
    delete(this);
}

void ship::place(struct s_coords *coords)
{
    for(int i=0;i<this->size;i++){
        this->coords[i].xCoord = coords[i].xCoord;
        this->coords[i].yCoord = coords[i].yCoord;
        this->coords[i].hit = false;
    }
    this->floating = true;
}

bool ship::hit(struct s_coords coord)
{
    for(int i=0;i<this->size;i++){
        if((this->coords[i].xCoord == coord.xCoord) && (this->coords[i].yCoord == coord.yCoord)){
            this->coords[i].hit = true;
            return true;
        }
    }
    return false;
}

bool ship::isFloating()
{
    if(!this->floating){
        return false;
    }
    for(int i=0;i<this->size;i++){
        if(!this->coords[i].hit)
            return true;
    }
    this->floating = false;
    return false;
}