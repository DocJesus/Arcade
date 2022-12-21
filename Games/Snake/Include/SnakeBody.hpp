#include "AEntity.hpp"

class SnakeBody : public AEntity
{

    public:
        SnakeBody(AGame *_gameMaster, const int &_coordY, const int &_coordX, const int &_direction) : AEntity(PLAYER_BODY, _gameMaster, _coordY, _coordX)
        {
            this->direction = _direction;
        }
        SnakeBody(AGame *_gameMaster, const int &_coordY, const int &_coordX) : SnakeBody(_gameMaster, _coordY, _coordX, PLAYER_BODY_UP)
        {
        }
        SnakeBody() : SnakeBody(nullptr, 0, 0, PLAYER_BODY_UP)
        {
        }
        ~SnakeBody()
        {}

        void Move(const int &_input = 0);

        void UpdatePos(const int &_input);

        void Die();

};