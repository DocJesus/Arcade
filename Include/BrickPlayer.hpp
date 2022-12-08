#include "AEntity.hpp"

class BrickPlayer : public AEntity
{
    public:
        BrickPlayer() : AEntity(PLAYER, 0, 0)
        {
            this->direction = PLAYER_UP;
        }
        BrickPlayer(const int &_limitY, const int &_limitX) : AEntity(PLAYER, _limitY, _limitX)
        {
            this->direction = PLAYER_UP;
        }
        ~BrickPlayer()
        {

        }

        // move the entity if inertia
        virtual void Update()
        {

        }

        // validate the input passed and move
        virtual void move(int _input)
        {
            switch (_input)
            {
                case INPUT_RIGHT: // move right
                    if (this->coordX < this->limitX)
                        this->coordX += 1;
                    this->direction = PLAYER_RIGHT;
                    break;
                case INPUT_LEFT: // move left
                    if (this->coordX > 1)
                        this->coordX -= 1;
                    this->direction = PLAYER_LEFT;
                    break;
                case INPUT_UP: // move up
                    if (this->coordY < this->limitY)
                        this->coordY += 1;
                    this->direction = PLAYER_UP;
                    break;
                case INPUT_DOWN: // move down
                    if (this->coordY > 1)
                        this->coordY -= 1;
                    this->direction = PLAYER_DOWN;
                    break;            
                default:
                    break;
            }
        }

};