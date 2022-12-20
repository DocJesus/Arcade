#include "BrickProjectile.hpp"
#include "AGame.hpp"

// validate the input passed and move
void BrickProjectile::Move(const int &_input)
{
    (void)_input;
    int prevY = this->coordY;
    int prevX = this->coordX;

    this->UpdatePos(_input);

    // cout << "Prev Coord " << prevY << " " << prevX << endl;
    // cout << "what is at " << this->coordY << " " << this->coordX << endl;
    shared_ptr<AEntity> next_tile = gameMaster->getEntityAt(this->coordY, this->coordX);
    // cout << "Bonjour" << endl;
    int i = 0;
    if (next_tile != nullptr && next_tile->getType() != BONUS)
    {
        while (next_tile != nullptr && next_tile->getType() != BONUS && i < 5)
        {
            if (next_tile->getType() == ENNEMY)
            {
                // cout << "hit an ennemy" << endl;
                next_tile->Die();
                this->setVelocity(-1);
            }

            this->Ricochet();

            if (next_tile->getType() >= 50 && next_tile->getType() <= 53)
            {
                // cout << "hit an Wall" << endl;
                // todo remove this
                if (this->getPosY() == 0)
                    this->direction = UP;
            }

            if (next_tile->getType() == PLAYER_UP)
            {
                this->setVelocity(1);
                this->direction = UP;
            }                    
            if (next_tile->getType() == PLAYER_BODY_LEFT)
            {
                this->direction = UP_LEFT;
                this->setVelocity(1);
            }                        
            if (next_tile->getType() == PLAYER_BODY_RIGHT)
            {
                this->direction = UP_RIGHT;
                this->setVelocity(1);
            }

            this->UpdatePos(_input);

            // cout << "what is at " << this->coordY << " " << this->coordX << endl;
            // check if we go out of the map
            next_tile = gameMaster->getEntityAt(this->coordY, this->coordX);
            i++;
        }
        gameMaster->EntityMoved(prevY, prevX, this->coordY, this->coordX);
    }
    else
    {
        // cout << prevY << " " << prevX << " " << this->coordY << " " << this->coordX;
        gameMaster->EntityMoved(prevY, prevX, this->coordY, this->coordX);
    }
}

void BrickProjectile::Ricochet()
{
    // cout << "Ricochet" << endl;
    if (this->velocity > 0)
    {
        if (this->direction == UP_RIGHT)
            this->direction = UP_LEFT;
        else if (this->direction == UP_LEFT)
            this->direction = UP_RIGHT;
    }
    else
    {
        if (this->direction == UP_RIGHT)
            this->direction = DOWN_LEFT;
        else if (this->direction == UP_LEFT)
            this->direction = DOWN_RIGHT;                
    }

    if (this->direction == DOWN_LEFT)
        this->direction = DOWN_RIGHT;                
    else if (this->direction == DOWN_RIGHT)
        this->direction = DOWN_LEFT;                
    else if (this->direction == UP)
        this->direction = DOWN;
    else if (this->direction == DOWN)
        this->direction = UP;

    // this->UpdatePos();
    // gameMaster->EntityMoved(prevY, prevX, this->coordY, this->coordX);
}

void BrickProjectile::UpdatePos(const int &_input)
{
    (void)_input;

    // cout << "direction of projectile " << this->direction << endl;
    switch (this->direction)
    {
        case RIGHT: // move right
            this->coordX += 1;
            break;
        case LEFT: // move left
            this->coordX -= 1;
            break;
        case UP: // move up
            this->coordY += 1;
            break;
        case DOWN: // move down
            this->coordY -= 1;
            break;
        case UP_LEFT: // move up left
            this->coordX -= 1;
            this->coordY += 1;
            break;
        case UP_RIGHT: // move up right
            this->coordX += 1;
            this->coordY += 1;
            break;
        case DOWN_RIGHT: // move down right
            this->coordX += 1;
            this->coordY -= 1;
            break;
        case DOWN_LEFT: // move down left
            this->coordX -= 1;
            this->coordY -= 1;
            break;
        default:
            break;
    }

    [](BrickProjectile *brick) { if (brick->getPosY() < 0) {brick->setY(1);}} (this);
    [](BrickProjectile *brick) { if (brick->getPosX() < 0) {brick->setX(1);}} (this);
    [](BrickProjectile *brick) { if (brick->getPosY() >= brick->getMaster()->getHeigh()) {brick->setY(brick->getMaster()->getHeigh() - 1);}}(this);
    [](BrickProjectile *brick) { if (brick->getPosX() >= brick->getMaster()->getWidth()) {brick->setX(brick->getMaster()->getWidth() - 1);}}(this);
}

void BrickProjectile::setVelocity(int _vel)
{
    this->velocity = _vel;
}
