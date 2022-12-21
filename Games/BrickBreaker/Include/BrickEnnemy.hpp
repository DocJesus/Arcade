#include "AEntity.hpp"

class BrickEnnemy : public AEntity
{
    public:
        BrickEnnemy(AGame *_gameMaster, const int &_coordY, const int &_coordX) : AEntity(ENNEMY, _gameMaster, _coordY, _coordX)
        {
        }
        BrickEnnemy(AGame *_gameMaster) : BrickEnnemy(_gameMaster, 0, 0)
        {
        }
        BrickEnnemy() : BrickEnnemy(nullptr, 0, 0)
        {
        }
        virtual ~BrickEnnemy()
        {
        }

        virtual void Move(const int &_input = 0);

        virtual void UpdatePos(const int &_input);

};