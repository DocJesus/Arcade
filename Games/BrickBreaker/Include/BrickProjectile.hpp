#include "AEntity.hpp"

class BrickProjectile : public AEntity
{
    private:
        int velocity;
    public:
        BrickProjectile() : AEntity(BONUS, nullptr, 0, 0)
        {
            this->direction = UP;
            this->velocity = 1;
        }
        BrickProjectile(AGame *_gameMaster, const int &_coordY, const int &_coordX) : AEntity(BONUS, _gameMaster, _coordY, _coordX)
        {
            this->direction = UP;
            this->velocity = 1;
        }
        virtual ~BrickProjectile()
        {

        }

        // validate the input passed and move
        void Move(const int &_input = 0);

        void Ricochet();

        void UpdatePos(const int &_input);

        void setVelocity(int _vel);
};