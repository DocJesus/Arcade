#include "AEntity.hpp"

class SnakeBody : public AEntity
{

    public:
        SnakeBody() : AEntity(PLAYER_BODY, nullptr, 0, 0)
        {
            this->direction = PLAYER_BODY_UP;
        }
        SnakeBody(AGame *_gameMaster, const int &_coordY, const int &_coordX) : AEntity(PLAYER_BODY, _gameMaster, _coordY, _coordX)
        {
            this->direction = PLAYER_BODY_UP;
        }
        ~SnakeBody()
        {}

        void Move(const int &_input = 0);

        void UpdatePos(const int &_input);

        void Die();

};