#include "AGame.hpp"

class BrickBreaker : public AGame
{
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

            this->startX = 2;
            this->startY = 1;

            this->startX = 0;
            this->startY = 0;


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

            // Placing player
            this->map[this->height - 2][this->width / 2] = PLAYER_UP;
            this->map[this->height - 2][(this->width / 2) - 1] = PLAYER_BODY;
            this->map[this->height - 2][(this->width / 2) - 2] = PLAYER_BODY;
            this->map[this->height - 2][(this->width / 2) + 1] = PLAYER_BODY;
            this->map[this->height - 2][(this->width / 2) + 2] = PLAYER_BODY;
            this->map[this->height - 3][this->width / 2] = BONUS;

            // Placing Bricks
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
        }
};
