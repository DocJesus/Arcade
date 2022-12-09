#include "AEntity.hpp"

class BrickPlayer : public AEntity
{
    private:
        int input;
    public:
        BrickPlayer() : AEntity(PLAYER_UP, nullptr, 0, 0)
        {
            this->direction = PLAYER_UP;
        }
        BrickPlayer(AGame *_gameMaster, const int &_coordY, const int &_coordX) : AEntity(PLAYER_UP, _gameMaster, _coordY, _coordX)
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
        void Move(const int &_input = 0)
        {
            int prevY = this->coordY;
            int prevX = this->coordX;
            this->input = _input;

            this->UpdatePos();
            shared_ptr<AEntity> next_tile = gameMaster->getEntityAt(this->coordY, this->coordX);
            if (next_tile == nullptr)
            {
                gameMaster->EntityMoved(prevY, prevX, this->coordY, this->coordX);
            }
            else
            {
                this->coordY = prevY;
                this->coordX = prevX;
            }
            
            /*
            else if (next_tile == type(BrickProjectile))
            {

            }
            */
        }

        void UpdatePos()
        {
            switch (this->input)
            {
                case RIGHT: // move right
                    this->coordX += 1;
                    break;
                case LEFT: // move left
                    this->coordX -= 1;
                    break;
                default:
                    break;
            }
        }

};