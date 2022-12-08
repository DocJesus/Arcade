#include "AEntity.hpp"

class BrickProjectile : public AEntity
{
    public:
        BrickProjectile() : AEntity(BONUS, 0, 0)
        {
            this->direction = UP;
            this->inertia = 1;
        }
        BrickProjectile(const int &_coordY, const int &_coordX) : AEntity(BONUS, _coordY, _coordX)
        {
            this->direction = UP;
            this->inertia = 1;
        }
        virtual ~BrickProjectile()
        {

        }

        // move the entity if inertia ?
        virtual void Update()
        {

        }

        // validate the input passed and move
        virtual tuple<int, int> move(int _input = 0)
        {
            (void)_input;
            tuple<int, int> prevCoord(this->coordY, this->coordX);

            switch (this->direction)
            {
                case RIGHT: // move right
                    if (this->coordX < this->limitX)
                        this->coordX += 1;
                    break;
                case LEFT: // move left
                    if (this->coordX > 1)
                        this->coordX -= 1;
                    break;
                case UP: // move up
                    if (this->coordY < this->limitY)
                        this->coordY += 1;
                    break;
                case DOWN: // move down
                    if (this->coordY > 1)
                        this->coordY -= 1;
                    break;
                case UP_LEFT: // move up left
                    if (this->coordX > 1 && this->coordY < this->limitY)
                    {
                        this->coordX -= 1;
                        this->coordY += 1;
                    }
                    break;
                case UP_RIGHT: // move up right
                    if (this->coordX < this->limitX && this->coordY < this->limitY)
                    {
                        this->coordX += 1;
                        this->coordY += 1;
                    }
                    break;
                case DOWN_RIGH: // move down right
                    if (this->coordX < this->limitX && this->coordY > 1)
                    {
                        this->coordX += 1;
                        this->coordY -= 1;
                    }
                    break;
                case DOWN_LEFT: // move down left
                    if (this->coordX > 1 && this->coordY > 1)
                    {
                        this->coordY -= 1;
                        this->coordX -= 1;
                    }
                    break;
                default:
                    break;
            }

            return prevCoord;
        }
};