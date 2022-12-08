#include "AEntity.hpp"

class Wall : public AEntity
{
    public:
        Wall() : AEntity(TOP_ROW, 0, 0)
        {
        }
        Wall(const int &type, const int &_coordY, const int &_coordX) : AEntity(type, _coordY, _coordX)
        {
        }
        virtual ~Wall()
        {

        }

        // move the entity if inertia ?
        virtual void Update()
        {

        }

        virtual tuple<int, int> move(int _input = 0)
        {
            (void)_input;
            tuple<int, int> norme;
            return norme;
        }

};