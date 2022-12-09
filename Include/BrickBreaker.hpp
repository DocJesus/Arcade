#include "AGame.hpp"
#include "BrickPlayer.hpp"
#include "BrickProjectile.hpp"
#include "Wall.hpp"

class BrickBreaker : public AGame
{
    private:
        shared_ptr<AEntity> player;
        shared_ptr<AEntity> bullet;

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
            this->startX = 0;
            this->startY = 0;

            // NB: cannot create vector of Abstract, pointers are required
            vector<vector<shared_ptr<AEntity>>> ent(this->height, vector<shared_ptr<AEntity>>(this->width, nullptr));
            this->entities = ent;

            // creating the Areana
            int y = 0;
            int x = 0;
            while (y < this->height)
            {
                x = 0;
                if (y == 0)
                {
                    while (x < this->width)
                    {
                        this->entities[y][x] = make_shared<Wall>(BOT_ROW, this, y, x);
                        x++;
                    }
                }
                else if (y == this->height - 1)
                {
                    while (x < this->width)
                    {
                        this->entities[y][x] = make_shared<Wall>(TOP_ROW, this, y, x);
                        x++;
                    }
                }
                else
                {
                    this->entities[y][0] = make_shared<Wall>(SIDE_ROW, this, y, 0);
                    this->entities[y][this->width - 1] = make_shared<Wall>(SIDE_ROW, this, y, this->width - 1);
                }
                y++;
            }

            this->entities[0][0] = make_shared<Wall>(CORNER, this, 0, 0);
            this->entities[this->height - 1][this->width - 1] = make_shared<Wall>(CORNER, this, this->height - 1, this->width - 1);
            this->entities[0][this->width - 1] = make_shared<Wall>(CORNER, this, 0, this->width - 1);
            this->entities[this->height - 1][0] = make_shared<Wall>(CORNER, this, this->height - 1, 0);


            // creating the player
            this->player = make_shared<BrickPlayer>(this, 1, this->width / 2);
            this->entities[1][this->width / 2] = this->player;

            // creating the bullet
            this->bullet = make_shared<BrickProjectile>(this, 2, this->width / 2);
            this->entities[2][this->width / 2] = this->bullet;

            // creating the ennemies


            vector<vector<int>> vec(this->height, vector<int>(this->width, EMPTY));
            this->map = vec;
        }
        virtual ~BrickBreaker()
        {

        }

        void InitGame()
        {
            // (RE)Placing Player
            this->player->setYX(1, this->width / 2);

            // this->map[this->height - 2][this->width / 2] = PLAYER_UP;
            // this->map[this->height - 2][(this->width / 2) - 1] = PLAYER_BODY;
            // this->map[this->height - 2][(this->width / 2) - 2] = PLAYER_BODY;
            // this->map[this->height - 2][(this->width / 2) + 1] = PLAYER_BODY;
            // this->map[this->height - 2][(this->width / 2) + 2] = PLAYER_BODY;

            // (RE)Placing Bullet
            this->bullet->setYX(2, this->width / 2);
            // this->map[this->height - 3][this->width / 2] = BONUS;

            // Placing Bricks
            /*
            y = 1;
            while (y < this->height / 2)
            {
                x = 1;
                while (x < this->width - 1)
                {
                    this->map[y][x] = ENNEMY;
                    x++;
                }
                y++;
            }
            */

           this->DrawBoard();
        }

        void GameUpdate(const int &_inputs)
        {
            cout << _inputs << endl;

            this->player->Move(_inputs);
            this->bullet->Move();

            /*
            tuple<int, int> prevCoord;

            // passer inputs au player
            // update la position du player
            prevCoord = this->player.move(_inputs);
            this->map[std::get<0>(prevCoord)][std::get<1>(prevCoord)] = EMPTY;

            // update la positon des bonus (si il y a)
            this->map[std::get<0>(prevCoord)][std::get<1>(prevCoord)] = EMPTY;

            // update la positon des ennemies (si il y a)
                // update si il y a colision quand on bouge une entité

            // update les collisions ?
            */
        }

        void DrawBoard()
        {
            int x = 0;
            int y = 0;
            while (y < this->height)
            {
                x = 0;
                while (x < this->width)
                {
                    this->map[y][x] = EMPTY;
                    if (this->entities[y][x] != nullptr)
                        this->map[y][x] = this->entities[y][x]->getType();
                    else
                        this->map[y][x] = EMPTY;
                    x++;
                }
                y++;
            }

            /*
            int next_tile;

            // Update pos of the player on the board
            x = this->player.getPosX();
            y = this->player.getPosY();
            this->map[y][x] = player.getDirection();

            // Update pos of the bullet on the board
            x = this->bullet.getPosX();
            y = this->bullet.getPosY();
            next_tile = this->map[y][x];
            while (next_tile != EMPTY)
            {
                this->bullet.ricochet(next_tile);
                x = this->bullet.getPosX();
                y = this->bullet.getPosY();
                next_tile = this->map[y][x];
            }
            next_tile = this->bullet.getType();
            */

        }

        void EntityMoved(const int &_prevY, const int &_prevX, const int &_nextY, const int &_nextX)
        {
            this->entities[_nextY][_nextX] = this->entities[_prevY][_prevX];
            this->entities[_prevY][_prevX] = nullptr;

            this->map[_nextY][_nextX] = this->entities[_nextY][_nextX]->getType();
            this->map[_prevY][_prevX] = EMPTY;           
        }

};
