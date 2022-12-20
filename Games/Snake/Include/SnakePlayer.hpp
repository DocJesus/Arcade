#include <vector>
#include <list>
#include "SnakeBody.hpp"
#include "AEntity.hpp"
#include "AGame.hpp"

class SnakePlayer : public AEntity
{
    private:
        // we need pointers bc this is an Abstract
        vector<shared_ptr<AEntity>> body;
        list<int> orders;

    public:
        SnakePlayer() : AEntity(PLAYER, nullptr, 0, 0)
        {
            this->direction = PLAYER;
        }
        SnakePlayer(AGame *_gameMaster, const int &_coordY, const int &_coordX) : AEntity(PLAYER, _gameMaster, _coordY, _coordX)
        {
            this->direction = PLAYER;

            // creating body of the player
            shared_ptr<AEntity> neck = make_shared<SnakeBody>(this->gameMaster, this->getPosY() - 1, this->getPosX());
            this->gameMaster->AddEntity(this->getPosY() - 1, this->getPosX(), neck);
            body.push_back(neck);

            shared_ptr<AEntity> tail = make_shared<SnakeBody>(this->gameMaster, this->getPosY() - 2, this->getPosX());
            this->gameMaster->AddEntity(this->getPosY() - 2, this->getPosX(), tail);
            body.push_back(tail);

            orders.push_back(UP);
            orders.push_back(UP);
        }
        virtual ~SnakePlayer()
        {

        }

        // validate the input passed and move
        void Move(const int &_input = 0);

        void UpdatePos(const int &_input);

        void Die();

        void AddBodyPart();
};