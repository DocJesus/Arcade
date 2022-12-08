#include "AGame.hpp"
#include "BrickPlayer.hpp"

class BrickBreaker : public AGame
{
    private:
        BrickPlayer player;

    public:
        BrickBreaker()
        {
            cout << "init BrickBreaker Game" << endl;
        }
        BrickBreaker(int _height, int _width)
        {
            cout << "building BrickBreaker width = " << _width;
            cout << "height = " << _height << endl;

            this->width = _width / 2;
            this->height = _height / 2;

            // the Origin is the bottom LEFT Corner of the map
            this->startX = 0;
            this->startY = 0;

            // NB: cannot create vector of Abstract, pointers are required
            // vector<AEntity> ent(1, BrickPlayer(PLAYER));
            // this->entities = ent;

            // creating the player
            this->player = BrickPlayer(this->height - 2, this->width - 2);

            // creating the ennemies

            vector<vector<int>> vec(this->height, vector<int>(this->width, EMPTY));
            this->map = vec;
        }
        virtual ~BrickBreaker()
        {

        }

        void InitGame()
        {
            // creating the BrickBreaker Map
            int y = 0;
            int x = 0;
            while (y < this->height)
            {
                x = 0;
                if (y == 0 || y == this->height - 1)
                {
                    while (x <= this->width)
                    {
                        this->map[y][x] = TOP_ROW;
                        x++;
                    }
                }
                else
                {
                    this->map[y][0] = SIDE_ROW;
                    this->map[y][this->width - 1] = SIDE_ROW;
                }
                y++;
            }
            this->map[0][0] = CORNER;
            this->map[this->height - 1][this->width - 1] = CORNER;
            this->map[0][this->width - 1] = CORNER;
            this->map[this->height - 1][0] = CORNER;

            // Giving entities their base coordinates
            // Placing Player
            this->player.setYX(1, this->width / 2);

            // this->map[this->height - 2][this->width / 2] = PLAYER_UP;
            // this->map[this->height - 2][(this->width / 2) - 1] = PLAYER_BODY;
            // this->map[this->height - 2][(this->width / 2) - 2] = PLAYER_BODY;
            // this->map[this->height - 2][(this->width / 2) + 1] = PLAYER_BODY;
            // this->map[this->height - 2][(this->width / 2) + 2] = PLAYER_BODY;

            // Placing Bonus
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

           this->BoardUpdate();
        }

        void GameUpdate(int _inputs)
        {
            cout << _inputs << endl;
            // passer inputs au player
            // update la position du player
            this->player.move(_inputs);

            // update la positon des bonus (si il y a)
            // update la positon des ennemies (si il y a)
                // update si il y a colision quand on bouge une entité
        }

        void BoardUpdate()
        {
            int x = 0;
            int y = 0;

            // Update pos of the player
            x = player.getPosX();
            y = player.getPosY();

            this->map[y][x] = player.getDirection();
        }
};
