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
        virtual void GameUpdate(const int &_inputs) = 0;

        // get coordinate from entities and palce them on the board
        virtual void DrawBoard() = 0;

        // move an Entity through the entities vector
        virtual void EntityMoved(const int &_prevY, const int &_prevX, const int &_nextY, const int &_nextX) = 0;

        vector<vector<int>> &getMap()
        {
            return this->map;
        }
        shared_ptr<AEntity> getEntityAt(const int &_coordY, const int &_coordX) const
        {
            return this->entities[_coordY][_coordX];
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