#include "AEntity.hpp"

class BrickPlayer : public AEntity
{
    public:
        BrickPlayer() : AEntity(PLAYER_UP, 0, 0)
        {
            this->direction = PLAYER_UP;
        }
        BrickPlayer(const int &_coordY, const int &_coordX) : AEntity(PLAYER_UP, _coordY, _coordX)
        {
            this->direction = PLAYER_UP;
        }
        virtual ~BrickPlayer()
        {

        }

        // move the entity if inertia ?
        virtual void Update()
        {

        }

        // validate the input passed and move
        virtual tuple<int, int> move(int _input = 0)
        {
            tuple<int, int> prevCoord(this->coordY, this->coordX);

            switch (_input)
            {
                case RIGHT: // move right
                    if (this->coordX < this->limitX)
                        this->coordX += 1;
                    break;
                case LEFT: // move left
                    if (this->coordX > 1)
                        this->coordX -= 1;
                    break;
                default:
                    break;
            }

            return prevCoord;
        }

};