#include "BrickPlayerBody.hpp"
#include "AGame.hpp"

void BrickPlayerBody::Move(const int &_input)
{
    int prevY = this->coordY;
    int prevX = this->coordX;

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
        default:
            break;
    }

    // cout << "BrickPlayerBodyMove " << prevY << " " << prevX << " " << this->coordY << " " << this->coordX << endl;
    gameMaster->EntityMoved(prevY, prevX, this->coordY, this->coordX);
}

void BrickPlayerBody::UpdatePos(const int &_input)
{
    (void)_input;
}
