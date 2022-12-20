#include "AGame.hpp"
#include "BrickPlayer.hpp"
#include "BrickProjectile.hpp"
#include "Wall.hpp"
#include "BrickEnnemy.hpp"
#include "AEntity.hpp"
#include "BrickPlayerBody.hpp"

class BrickBreaker : public AGame
{
    private:
        shared_ptr<BrickPlayer> player;
        shared_ptr<BrickProjectile> bullet;

    public:
        BrickBreaker()
        {
            cout << "init BrickBreaker Game" << endl;
        }
        BrickBreaker(const int &_height, const int &_width)
        {
            cout << "building BrickBreaker width = " << _width;
            cout << "height = " << _height << endl;

            this->width = _width / 2;
            this->height = _height / 2;

            // the Origin is the bottom LEFT Corner of the map 
            // NB: cannot create vector of Abstract, pointers are required
            vector<vector<shared_ptr<AEntity>>> ent(this->height, vector<shared_ptr<AEntity>>(this->width, nullptr));
            this->entities = ent;

            // creating the Areana
            this->CreateArena();

            // creating the player
            this->player = make_shared<BrickPlayer>(this, 1, this->width / 2);
            this->entities[this->player->getPosY()][this->player->getPosX()] = this->player;

            // placing the body of the player
            vector<shared_ptr<AEntity>> playerLeftWing = player->getLeftWing();
            vector<shared_ptr<AEntity>> playerRightWing = player->getRightWing();

            int x = 0;
            while (x < this->player->getWidth() / 2)
            {
                cout << playerRightWing[x]->getType() << endl;
                this->entities[playerRightWing[x]->getPosY()][playerRightWing[x]->getPosX()] = playerRightWing[x];

                cout << playerLeftWing[x]->getType() << endl;
                this->entities[playerLeftWing[x]->getPosY()][playerLeftWing[x]->getPosX()] = playerLeftWing[x];

                x++;
            }

            // creating the bullet
            this->bullet = make_shared<BrickProjectile>(this, 2, this->width / 2);
            this->entities[this->bullet->getPosY()][this->bullet->getPosX()] = this->bullet;

            vector<vector<int>> vec(this->height, vector<int>(this->width, EMPTY));
            this->map = vec;
        }
        virtual ~BrickBreaker()
        {

        }

        void InitGame();
        void GameUpdate(const int &_inputs);
};
