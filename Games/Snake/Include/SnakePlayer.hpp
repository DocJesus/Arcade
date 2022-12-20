#include "AEntity.hpp"

class SnakePlayer : public AEntity
{
    public:
        SnakePlayer() : AEntity(PLAYER, nullptr, 0, 0)
        {
            this->direction = PLAYER;
        }
        SnakePlayer(AGame *_gameMaster, const int &_coordY, const int &_coordX) : AEntity(PLAYER, _gameMaster, _coordY, _coordX)
        {
            this->direction = PLAYER;

            // creating body of the player
        }
        virtual ~SnakePlayer()
        {

        }

        // validate the input passed and move
        void Move(const int &_input = 0);

        void UpdatePos(const int &_input);

        void Die();

};