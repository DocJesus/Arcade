#include <memory>
#include "SnakePlayer.hpp"
#include "Wall.hpp"
#include "AEntity.hpp"
#include "AGame.hpp"

class Snake : public AGame
{
    private:
        shared_ptr<SnakePlayer> player;
        // vector<shared_ptr<SnakeBody>> body;

    public:
        Snake()
        {
            cout << "init Snake Game" << endl;
        }
        Snake(int _height, int _width)
        {
            cout << "building Snake width = " << _width;
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
            this->player = make_shared<SnakePlayer>(this, 1, this->width / 2);
            this->entities[1][this->player->getPosX()] = this->player;

            // creating the body of the player

            // placing the fruits

            vector<vector<int>> vec(this->height, vector<int>(this->width, EMPTY));
            this->map = vec;
        }
        ~Snake()
        {
        }

        void InitGame();

        void GameUpdate(const int &_inputs);

};