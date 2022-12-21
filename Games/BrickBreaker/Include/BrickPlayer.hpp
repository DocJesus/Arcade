#include <vector>

#include "BrickPlayerBody.hpp"
#include "AEntity.hpp"

class BrickPlayer : public AEntity
{
    private:
        int width;

        vector<shared_ptr<AEntity>> leftWing;
        vector<shared_ptr<AEntity>> rightWing;

    public:
        BrickPlayer(AGame *_gameMaster, const int &_coordY, const int &_coordX) : AEntity(PLAYER, _gameMaster, _coordY, _coordX)
        {
            this->width = 5; // better be an odd number
            this->direction = PLAYER;

            // creating body of the player
            int i = 0;
            while (i < this->width / 2)
            {
                this->leftWing.push_back(make_shared<BrickPlayerBody>(PLAYER_BODY_LEFT, this->gameMaster, this->getPosY(), this->getPosX() + i - (this->width / 2)));
                this->rightWing.push_back(make_shared<BrickPlayerBody>(PLAYER_BODY_RIGHT, this->gameMaster, this->getPosY(), this->getPosX() + i + 1));
                i++;
            }
        }
        BrickPlayer(AGame *_gameMaster) : BrickPlayer(_gameMaster, 0, 0)
        {            
        }
        BrickPlayer() : BrickPlayer(nullptr, 0, 0)
        {
        }
        virtual ~BrickPlayer()
        {

        }

        // validate the input passed and move
        void Move(const int &_input = 0);

        void UpdatePos(const int &_input);

        void Die();

        void MovePlayerBody(const bool &_reverse, const int &_input);

        const int &getWidth() const;

        const vector<shared_ptr<AEntity>> &getLeftWing() const;

        const vector<shared_ptr<AEntity>> &getRightWing() const;
};