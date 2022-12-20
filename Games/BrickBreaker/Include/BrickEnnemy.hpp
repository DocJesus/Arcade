#include "AEntity.hpp"

class BrickEnnemy : public AEntity
{
    public:
        BrickEnnemy() : AEntity(ENNEMY, nullptr, 0, 0)
        {
        }
        BrickEnnemy(AGame *_gameMaster, const int &_coordY, const int &_coordX) : AEntity(ENNEMY, _gameMaster, _coordY, _coordX)
        {
        }
        virtual ~BrickEnnemy()
        {
        }

        virtual void Move(const int &_input = 0);

        virtual void UpdatePos(const int &_input);

};