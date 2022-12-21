#include "AGame.hpp"
#include "AEntity.hpp"

class SnakeFruit : public AEntity
{
    public:
        SnakeFruit(AGame *_gameMaster, const int &_coordY, const int &_coordX) : AEntity(BONUS, _gameMaster, _coordY, _coordX)
        {}
        SnakeFruit(AGame *_gameMaster) : SnakeFruit(_gameMaster, 0, 0)
        {}
        SnakeFruit() : SnakeFruit(nullptr, 0, 0)
        {}
        SnakeFruit(SnakeFruit *_fruit)
        {
            this->setX(_fruit->getPosX());
            this->setY(_fruit->getPosY());
            this->setType(_fruit->getType());
            this->setGM(_fruit->getMaster());
            this->setDir(_fruit->getDirection());
        }
        ~SnakeFruit()
        {}

        void Move(const int &_input = 0);

        void UpdatePos(const int &_input);

        void Die();
};