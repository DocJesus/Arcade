#include <tuple>
#include "state.h"

#ifndef H_AEntity
#define H_AEntity

using namespace std;
class AGame;

class AEntity
{
    protected:
        int coordX;
        int coordY;
        int type;

        int direction; // for animated Entity only // subclass for wall and/or animated ?
        AGame *gameMaster; // for animated Entity only

    public:
        // use the type defined in state.h
        AEntity(int _type, AGame *_gameMaster, int _coordY, int _coordX)
        {
            this->type = _type;
            this->gameMaster = _gameMaster;
            this->coordY = _coordY;
            this->coordX = _coordX;
        }
        virtual ~AEntity()
        {

        }

        // virtual void resetPosition(int _coordY, int _coordX) = 0;

        // only for animated Entity ?
        // move the entity if inertia
        virtual void Update() = 0;
        // validate the input passed, move and handle Collisions
        virtual void Move(const int &_input = 0) = 0;
        // update the position of the entity
        virtual void UpdatePos() = 0;

        void setYX(int _newY, int _newX)
        {
            this->coordY = _newY;
            this->coordX = _newX;
        }

        const int &getPosX() const
        {
            return this->coordX;
        }
        const int &getPosY() const
        {
            return this->coordY;
        }
        const int &getType() const
        {
            return this->type;
        }
        const int &getDirection() const
        {
            return this->direction;
        }
};

#endif