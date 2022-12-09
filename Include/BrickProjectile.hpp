#include "AEntity.hpp"

class BrickProjectile : public AEntity
{
    public:
        BrickProjectile() : AEntity(BONUS, nullptr, 0, 0)
        {
            this->direction = UP;
        }
        BrickProjectile(AGame *_gameMaster, const int &_coordY, const int &_coordX) : AEntity(BONUS, _gameMaster, _coordY, _coordX)
        {
            this->direction = UP;
        }
        virtual ~BrickProjectile()
        {

        }

        // move the entity if inertia ?
        virtual void Update()
        {

        }

        // validate the input passed and move
        void Move(const int &_input = 0)
        {
            (void)_input;
            int prevY = this->coordY;
            int prevX = this->coordX;

            this->UpdatePos();

            shared_ptr<AEntity> next_tile = gameMaster->getEntityAt(this->coordY, this->coordX);
            if (next_tile != nullptr && next_tile->getType() != BONUS)
            {
                // if (next_tile == BrickEnnemy)
                    // kill it lol
                // gameMaster->EntityMoved(this, prevY, prevX, this->coordY, this->coordX);
                this->Ricochet();
                this->Move();
            }
            else
                gameMaster->EntityMoved(prevY, prevX, this->coordY, this->coordX);
        }

        void Ricochet()
        {
            if (this->direction % 2 == 0)
                this->direction += 1;
            else
                this->direction -= 1;
            this->UpdatePos();
        }

        void UpdatePos()
        {
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
                case DOWN_RIGH: // move down right
                    this->coordX += 1;
                    this->coordY -= 1;
                    break;
                case DOWN_LEFT: // move down left
                    this->coordY -= 1;
                    this->coordX -= 1;
                    break;
                default:
                    break;
            }
        }
};