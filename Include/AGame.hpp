#include <iostream>
#include <vector>
#include "state.h"
#include "AEntity.hpp"

using namespace std;

class AGame
{
    protected:
        vector<vector<int>> map;
        vector<vector<shared_ptr<AEntity>>> entities;

        // the origin is the bottom LEFT Corner of the map
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

        // give basic coordinate to Entities
        // draw the base of the map
        virtual void InitGame() = 0;

        // pass the input to the entities (like player)
        // update the position of all entities
        // handle collision ?
        virtual void GameUpdate(int _inputs) = 0;

        // get coordinate from entities and palce them on the board
        virtual void BoardUpdate() = 0;

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