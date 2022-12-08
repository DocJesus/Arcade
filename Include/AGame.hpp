#include <iostream>
#include <vector>

using namespace std;

#define EMPTY 0
#define PLAYER_UP 1
#define PLAYER_RIGHT 2
#define PLAYER_LEFT 3
#define PLAYER_DOWN 4
#define PLAYER_BODY 5
#define BONUS 10
#define ENNEMY 11
#define TOP_ROW 50
#define SIDE_ROW 51
#define CORNER 52

class AGame
{
    protected:
        vector<vector<int>> map;
        int startX;
        int startY;
        int width;
        int height;


    public:
        AGame()
        {
        }
        virtual ~AGame()
        {
        }

        virtual void InitGame() = 0;

        vector<vector<int>> &getMap()
        {
            return this->map;
        }

        const int &getStartPosX() const
        {
            return this->startX;
        }
        const int &getStartPosY() const
        {
            return this->startY;
        }

        void getStartPos(int *_posX, int *_posY) const
        {
            *_posX = this->startX;
            *_posY = this->startY;
        }
        void getHeightWidth(int *_height, int *_width) const
        {
            *_height = this->height;
            *_width = this->width;
        }
};