#include "../include/ship.hpp"

ship::ship(){}

ship::ship(int id, int size, const char* name)
{
    this->id = id;
    this->size = size;
    this->name = (char*) malloc(sizeof(char)*strlen(name));
    strcpy(this->name, name);
    this->coords = (struct s_coords*) malloc(sizeof(struct s_coords)*size);
    // initial values
    for(int i=0;i<size;i++){
        this->coords[i].xCoord = -1;
        this->coords[i].yCoord = -1;
        this->coords[i].hit = false;
    }
    this->floating = false;
}

ship::~ship()
{
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
        if(!this->coords[i].hit){
            return true;
        }
    }
    this->floating = false;
    return false;
}

int ship::getSize()
{
    return this->size;
}

char* ship::getName(){
    return this->name;
}