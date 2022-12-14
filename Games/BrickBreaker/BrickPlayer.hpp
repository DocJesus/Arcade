#include "BrickPlayerBody.hpp"
#include "AEntity.hpp"

class BrickPlayer : public AEntity
{
    private:
        int input;
        int width;

        vector<shared_ptr<AEntity>> leftWing;
        vector<shared_ptr<AEntity>> rightWing;

        // vector<shared_ptr<AEntity>> playerBody;

    public:
        BrickPlayer() : AEntity(PLAYER_UP, nullptr, 0, 0)
        {
            this->width = 5;
            this->direction = PLAYER_UP;

            int i = 0;
            while (i < this->width / 2)
            {
                this->leftWing.push_back(make_shared<BrickPlayerBody>(PLAYER_BODY_LEFT, this->gameMaster, this->getPosY(), this->getPosX() + i - (this->width / 2)));
                this->rightWing.push_back(make_shared<BrickPlayerBody>(PLAYER_BODY_RIGHT, this->gameMaster, this->getPosY(), this->getPosX() + i + 1));
                i++;
            }
        }
        BrickPlayer(AGame *_gameMaster, const int &_coordY, const int &_coordX) : AEntity(PLAYER_UP, _gameMaster, _coordY, _coordX)
        {
            this->width = 5; // better be an odd number
            this->direction = PLAYER_UP;

            // creating body of the player
            int i = 0;
            while (i < this->width / 2)
            {
                this->leftWing.push_back(make_shared<BrickPlayerBody>(PLAYER_BODY_LEFT, this->gameMaster, this->getPosY(), this->getPosX() + i - (this->width / 2)));
                this->rightWing.push_back(make_shared<BrickPlayerBody>(PLAYER_BODY_RIGHT, this->gameMaster, this->getPosY(), this->getPosX() + i + 1));
                i++;
            }
        }
        virtual ~BrickPlayer()
        {

        }

        // validate the input passed and move
        void Move(const int &_input = 0)
        {
            int prevY = this->coordY;
            int prevX = this->coordX;
            this->input = _input;

            this->UpdatePos();

            // check the collision with the side that is in the direction of the move
            shared_ptr<AEntity> next_tile = nullptr;
            if (this->direction == PLAYER_RIGHT)
                next_tile = gameMaster->getEntityAt(this->coordY, this->coordX + (this->width / 2));
            else
                next_tile = gameMaster->getEntityAt(this->coordY, this->coordX - (this->width / 2));
            

            if (next_tile == nullptr)
            {
                // move the side of the player
                MovePlayerBody(false, _input);

                // move the player
                // cout << "moving player" << endl;
                // cout << "BrickPlayerBodyMove " << prevY << " " << prevX << " " << this->coordY << " " << this->coordX << endl;
                gameMaster->EntityMoved(prevY, prevX, this->coordY, this->coordX);

                // move the OTHER side of the player
                MovePlayerBody(true, _input);

            }
            else
            {
                this->coordY = prevY;
                this->coordX = prevX;
            }


            /*
            else if (next_tile == type(BrickProjectile))
            {

            }
            */
        }

        void UpdatePos()
        {
            switch (this->input)
            {
                case RIGHT: // move right
                    this->coordX += 1;
                    this->direction = PLAYER_RIGHT;
                    break;
                case LEFT: // move left
                    this->coordX -= 1;
                    this->direction = PLAYER_LEFT;
                    break;
                default:
                    break;
            }
        }

        void Die()
        {
            
        }

        void MovePlayerBody(const bool &_reverse, const int &_input)
        {
            if (_input == RIGHT && !_reverse) // moving the right part to the right
            {
                for (auto it = this->rightWing.rbegin(); it != this->rightWing.rend(); ++it)
                    (*it) ->Move(_input);
            }
            else if (_input == LEFT && !_reverse) // moving the left part to the left
            {
                for (auto it : this->leftWing)
                    it->Move(_input);
            }
            else if (_input == LEFT && _reverse) //moving the right part to the left
            {
                for (auto it : this->rightWing)
                    it->Move(_input);
            }
            else if (_input == RIGHT && _reverse) // moving the left part to the right
            {
                for (auto it = this->leftWing.rbegin(); it != this->leftWing.rend(); ++it)
                    (*it) ->Move(_input);
            }            
        }

        const int &getWidth() const
        {
            return this->width;
        }
        const vector<shared_ptr<AEntity>> &getLeftWing() const
        {
            return this->leftWing;
        }
        const vector<shared_ptr<AEntity>> &getRightWing() const
        {
            return this->rightWing;
        }
};