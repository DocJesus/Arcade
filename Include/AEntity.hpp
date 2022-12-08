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
        int limitX;
        int limitY;
        int inertia;
        int direction;
        int type;

        shared_ptr<AGame> gameMaster;

        bool collision; // useless ?
        bool moved; // useless ?

    public:
        // use the type defined in state.h
        AEntity(int _type, int _coordY, int _coordX)
        {
            this->type = _type;
            this->coordY = _coordY;
            this->coordX = _coordX;
        }
        virtual ~AEntity()
        {

        }

        // virtual void resetPosition(int _coordY, int _coordX) = 0;

        // move the entity if inertia
        virtual void Update() = 0;
        // validate the input passed and move
        // return the coordinate where the Entity was (Y,X)
        virtual tuple<int, int> move(int _input = 0) = 0;


        void setCol(bool _isCol)
         {
             this->collision = _isCol;
         }
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