#include "SnakePlayer.hpp"
#include "AGame.hpp"

// validate the input passed and move
void SnakePlayer::Move(const int &_input)
{
    int prevY = this->coordY;
    int prevX = this->coordX;

    this->UpdatePos(_input);

    // check the collision with the side that is in the direction of the move
    shared_ptr<AEntity> next_tile = nullptr;

    switch (this->direction)
    {
        case PLAYER_RIGHT:
            next_tile = gameMaster->getEntityAt(this->coordY, this->coordX + 1);
            break;
        case PLAYER_LEFT:
            next_tile = gameMaster->getEntityAt(this->coordY, this->coordX - 1);
            break;
        case PLAYER_UP:
            next_tile = gameMaster->getEntityAt(this->coordY + 1, this->coordX);
            break;
        case PLAYER_DOWN:
            next_tile = gameMaster->getEntityAt(this->coordY - 1, this->coordX);
            break;                
        default:
            break;
    }

    if (next_tile == nullptr)
    {
        // move the player
        gameMaster->EntityMoved(prevY, prevX, this->coordY, this->coordX);

        // move the body of the player
        // MovePlayerBody(true, _input);

    }
    else
    {
        this->coordY = prevY;
        this->coordX = prevX;
    }

}

void SnakePlayer::UpdatePos(const int &_input)
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
        case UP: // move up
            this->coordY += 1;
            this->direction = PLAYER_UP;
            break;
        case DOWN: // move down
            this->coordY -= 1;
            this->direction = PLAYER_DOWN;
            break;
        default:
            break;
    }
}

void SnakePlayer::Die()
{
    
}
