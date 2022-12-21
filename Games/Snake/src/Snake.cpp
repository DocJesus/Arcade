#include "Snake.hpp"
#include "AGame.hpp"

void Snake::InitGame()
{
    // special
    
    /*
    for (int i = 0; i < 18; i++)
    {
        this->player->Move(UP);
    }
    */
    
    this->DrawBoard();
}

void Snake::GameUpdate(const int &_inputs)
{
    // cout << _inputs << endl;

    this->player->Move(_inputs);
    this->DrawBoard();
}
