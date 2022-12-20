#include "BrickPlayer.hpp"
#include "AGame.hpp"

// validate the input passed and move
void BrickPlayer::Move(const int &_input)
{
    int prevY = this->coordY;
    int prevX = this->coordX;

    this->UpdatePos(_input);

    // check the collision with the side that is in the direction of the move
    shared_ptr<AEntity> next_tile = nullptr;
    if (this->direction == PLAYER_RIGHT)
        next_tile = this->gameMaster->getEntityAt(this->coordY, this->coordX + (this->width / 2));
    else
        next_tile = this->gameMaster->getEntityAt(this->coordY, this->coordX - (this->width / 2));
    

    if (next_tile == nullptr)
    {
        // move the side of the player
        MovePlayerBody(false, _input);

        // move the player
        this->gameMaster->EntityMoved(prevY, prevX, this->coordY, this->coordX);

        // move the OTHER side of the player
        MovePlayerBody(true, _input);

        // reset the direction to player up so the sprite is the correct one
        this->direction = PLAYER_UP;
    }
    else
    {
        this->coordY = prevY;
        this->coordX = prevX;
    }

}

void BrickPlayer::UpdatePos(const int &_input)
{
    switch (_input)
    {
        case RIGHT: // move right
            this->coordX += 1;
            this->direction = PLAYER_RIGHT;
            break;
        case LEFT: // move left
            this->coordX -= 1;
            this->direction = PLAYER_LEFT;
            break;
        default:
            break;
    }
}

void BrickPlayer::Die()
{
    
}

void BrickPlayer::MovePlayerBody(const bool &_reverse, const int &_input)
{
    if (_input == RIGHT && !_reverse) // moving the right part to the right
    {
        for (auto it = this->rightWing.rbegin(); it != this->rightWing.rend(); ++it)
            (*it) ->Move(_input);
    }
    else if (_input == LEFT && !_reverse) // moving the left part to the left
    {
        for (auto it : this->leftWing)
            it->Move(_input);
    }
    else if (_input == LEFT && _reverse) //moving the right part to the left
    {
        for (auto it : this->rightWing)
            it->Move(_input);
    }
    else if (_input == RIGHT && _reverse) // moving the left part to the right
    {
        for (auto it = this->leftWing.rbegin(); it != this->leftWing.rend(); ++it)
            (*it) ->Move(_input);
    }            
}

const int &BrickPlayer::getWidth() const
{
    return this->width;
}
const vector<shared_ptr<AEntity>> &BrickPlayer::getLeftWing() const
{
    return this->leftWing;
}
const vector<shared_ptr<AEntity>> &BrickPlayer::getRightWing() const
{
    return this->rightWing;
}
