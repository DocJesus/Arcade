#include "AEntity.hpp"

#ifndef H_BrickPlayerBody
#define H_BrickPlayerBody


class BrickPlayerBody : public AEntity
{
    public:
        BrickPlayerBody() : AEntity(PLAYER_BODY, nullptr, 0, 0)
        {

        }
        BrickPlayerBody(int _type, AGame *_gameMaster, const int &_coordY, const int &_coordX) : AEntity(_type, _gameMaster, _coordY, _coordX)
        {

        }
        ~BrickPlayerBody()
        {
            
        }

        void Move(const int &_input = 0);

        void UpdatePos(const int &_input);
};

#endif