#include "../include/board.hpp"


const char lineNames[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
const char* shipNames[5] = {"DESTROYER", "SUBMARINE", "CRUISER", "BATTLESHIP", "CARRIER"};
const int shipSizes[5] = {2, 3, 3, 4, 5};

board::board()
{
    for(int i=0; i<5; i++){
        this->fleet[i] = ship(i, shipSizes[i], shipNames[i]);
    }
    
    this->table = (int**) malloc(sizeof(int*)*10);
    for(int i=0; i<10; i++)
        this->table[i] = (int*)calloc(10, sizeof(int));
}

board::~board()
{
    for(int i=0; i<10; i++)
        free(this->table[i]);
    free(this->table);
}

bool board::placeOnBoard(int shipKind, int orientation, struct s_coords tail)
{
    ship* s;
    int end;
    int curSize;
    struct s_coords* coordlist;
    printf("Enter %s\n",__func__);
    // Perform checks before placing ship to coords
    s = &this->fleet[shipKind];
    if(tail.xCoord > 9 || tail.yCoord > 9)
        return false;
    if(s->getSize() > tail.xCoord && orientation == HORIZONTAL)
        return false;
    if(s->getSize() > tail.yCoord && orientation == VERTICAL)
        return false;
    
    // Create coords for placement
    coordlist = (struct s_coords*) malloc(sizeof(struct s_coords)*s->getSize());
    if(orientation){
        end = tail.xCoord;
        for(int i=0;i<s->getSize();i++){
            coordlist[i].xCoord = end;
            coordlist[i].yCoord = tail.yCoord;
            end--;
        }
    }else{
        end = tail.yCoord;
        for(int i=0;i<s->getSize();i++){
            coordlist[i].yCoord = end;
            coordlist[i].xCoord = tail.xCoord;;
            end--;
        }
    }
    // check if there are already ships there
    for(int i=0;i<s->getSize();i++){
        if(this->table[coordlist[i].yCoord][coordlist[i].xCoord] == 1)
            return false;
    }
    // Actual placement
    s->place(coordlist);
    for(int i=0;i<s->getSize();i++)
        this->table[coordlist[i].yCoord][coordlist[i].xCoord] = 1;
    free(coordlist);

    printf("Exit %s\n",__func__);
    return true;
}

bool board::bombard(struct s_coords target)
{
    bool isHit;
    for(int i=0;i<5;i++){
        isHit = this->fleet[i].hit(target);
        if(isHit){
            this->table[target.yCoord][target.xCoord] = 2;
            return isHit;
        }
        this->fleet[i].isFloating();
    }
    return false;
}

void board::showStatus(){
    printf("  ");
    for(int j=0;j<10;j++)
        printf("| %d ", j);
    printf("|\n");

    for(int j=0;j<42;j++)
        printf("-");
    printf("\n");

    for(int i=0;i<10;i++){
        printf("%c ", lineNames[i]);
        for(int j=0;j<10;j++){
            printf("| %d ", this->table[i][j]);
        }
        printf("|\n");

        for(int j=0;j<42;j++)
            printf("-");
        printf("\n");
    }
}

void board::showShips(){
    printf("Current Ships:\n");
    for(int i=0;i<5;i++){
        if(this->fleet[i].isFloating())
            printf("%s: size %d\n",this->fleet[i].getName() ,this->fleet[i].getSize());
    }
}