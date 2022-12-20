#include "Snake.hpp"
#include "AGame.hpp"

void Snake::InitGame()
{
    // special
    // this->player->Move(RIGHT);
    this->DrawBoard();
}

void Snake::GameUpdate(const int &_inputs)
{
    // cout << _inputs << endl;

    this->player->Move(_inputs);
    this->DrawBoard();
}
