class Player
{
public:
    int x, y;
    int speed;

    void move(int xa, int ya)
    {
        x += xa * speed;
        y += ya * speed;
    }
};


int createPlayer() {
    Player manish; // instantiated a new Player object!
    manish.x = 5;
    manish.y = 20;
    manish.speed = 35;
    manish.move(1, -1);
}