#include "BrickBreaker.hpp"

void BrickBreaker::InitGame()
{
    // (RE)Placing Player
    // this->player->setYX(1, this->width / 2);

    // (RE)Placing Bullet
    // this->bullet->setYX(2, this->width / 2);

    // (RE)Placing Bricks
    /*
    int y = 0;
    int x = 0;

    y = this->height / 2;
    while (y < this->height - 1)
    {
        x = 1;
        while (x < this->width - 1)
        {
            this->entities[y][x] = make_shared<BrickEnnemy>(this, y, x);
            x++;
        }
        y++;
    }
    */


    // special
    // this->player->Move(RIGHT);
    this->DrawBoard();
}

void BrickBreaker::GameUpdate(const int &_inputs)
{
    // cout << _inputs << endl;

    this->player->Move(_inputs);
    this->bullet->Move();

    this->DrawBoard();
}
