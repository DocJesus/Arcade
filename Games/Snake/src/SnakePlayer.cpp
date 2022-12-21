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
    next_tile = gameMaster->getEntityAt(this->coordY, this->coordX);

    if (next_tile == nullptr || (next_tile != nullptr && next_tile->getType() == BONUS))
    {
        if (next_tile != nullptr && next_tile->getType() == BONUS)
        {
            next_tile->Die();
            this->AddBodyPart();
        }

        // move the player
        gameMaster->EntityMoved(prevY, prevX, this->coordY, this->coordX);

        // move the body of the player
        int i = 0;
        for (auto it : this->orders)
        {
            this->body[i]->Move(it);
            i++;
        }

        this->orders.pop_back();
        this->orders.push_front(_input);
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

void SnakePlayer::AddBodyPart()
{
    int lastX = this->body[this->body.size() - 1]->getPosX();
    int lastY = this->body[this->body.size() - 1]->getPosY();
    int lastDir = this->body[this->body.size() - 1]->getDirection();

    int last_order = orders.back();

    switch (last_order)
    {
        case UP:
            lastY -= 1;
            break;
        case DOWN:
            lastY += 1;
            break;
        case LEFT:
            lastX += 1;
            break;
        case RIGHT:
            lastX -= 1;
            break;        
        default:
            break;
    }

    shared_ptr<AEntity> new_tail = make_shared<SnakeBody>(this->gameMaster, lastY, lastX, lastDir);
    this->gameMaster->AddEntity(lastY, lastX, new_tail);
    this->body.push_back(new_tail);
    orders.push_back(last_order);
}