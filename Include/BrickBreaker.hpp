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

            vector<vector<int>> vec(this->height, vector<int>(this->width, 0));

            int y = 0;
            int x = 0;

            while (y < this->height)
            {
                cout << "he he" << endl;
                x = 0;
                if (y == 0 || y == this->height - 1)
                {
                    while (x <= this->width)
                    {
                        vec[y][x] = 5;
                        x++;
                    }
                }
                else
                {
                    vec[y][0] = 5;
                    vec[y][this->width - 1] = 5;
                }
                
                y++;
            }

            cout << vec[1][this->width] << endl;
            this->map = vec;
        }
        virtual ~BrickBreaker()
        {

        }
};
