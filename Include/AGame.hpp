#include <iostream>
#include <vector>

using namespace std;

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