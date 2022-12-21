#include "AGame.hpp"
#include "SnakeBody.hpp"

void SnakeBody::Move(const int &_input)
{
    int prevY = this->coordY;
    int prevX = this->coordX;

    this->UpdatePos(_input);

    // check the collision with the side that is in the direction of the move
    shared_ptr<AEntity> next_tile = nullptr;
    next_tile = gameMaster->getEntityAt(this->coordY, this->coordX);

    if (next_tile == nullptr)
    {
        // move the entity
        gameMaster->EntityMoved(prevY, prevX, this->coordY, this->coordX);
    }
    else
    {
        cout << next_tile->getType() << endl;
        this->coordY = prevY;
        this->coordX = prevX;
    }

}

void SnakeBody::UpdatePos(const int &_input)
{
    switch (_input)
    {
        case RIGHT: // move right
            this->coordX += 1;
            this->direction = PLAYER_BODY_RIGHT;
            break;
        case LEFT: // move left
            this->coordX -= 1;
            this->direction = PLAYER_BODY_LEFT;
            break;
        case UP: // move up
            this->coordY += 1;
            this->direction = PLAYER_BODY_UP;
            break;
        case DOWN: // move down
            this->coordY -= 1;
            this->direction = PLAYER_BODY_DOWN;
            break;
        default:
            break;
    }
}

void SnakeBody::Die()
{

}