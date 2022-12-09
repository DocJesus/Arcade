#include "AEntity.hpp"

class Wall : public AEntity
{
    public:
        Wall() : AEntity(TOP_ROW, nullptr, 0, 0)
        {
        }
        Wall(const int &type, AGame *_gameMaster, const int &_coordY, const int &_coordX) : AEntity(type, _gameMaster, _coordY, _coordX)
        {
        }
        virtual ~Wall()
        {

        }

        virtual void Update()
        {

        }

        // Walls don't move
        void Move(const int &_input = 0)
        {
            (void)_input;
        }
        void UpdatePos()
        {

        }

};