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
    bool floating;
    struct s_coords *coords;
public:
    ship();
    ship(int id, int size, char* name);
    ~ship();
    void place(struct s_coords *coords);
    bool hit(struct s_coords coord);
    bool isFloating();
};